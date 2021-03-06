#include <unistd.h>
#include <iostream>
#include <thread>
#include <sstream>
#include "server/headers/model/Server.h"
#include "common/headers/Chronometer.h"

Server::Server(const std::string &port) :
        protocol(port), keep_accepting(true), active_game(true), nextPlayerId(1) {
    map.initializeTerrain(terrain);
}

Server::~Server() {
    clients.clearAll();
}

void Server::run() {
    std::thread acceptingThread(&Server::acceptClients, this);
    std::thread broadcastThread(&Server::broadCast, this);
    std::thread finishThread(&Server::finish, this);  // TODO Multiples partidas

    gameLoop();

    acceptingThread.join();
    broadcastThread.join();
    finishThread.join();
}

void Server::gameLoop() {
    Chronometer chronometer;

    while (active_game) {
        chronometer.tick();
        manageEvents();  // Acá se manejan los eventos de la cola protegida
        uint64_t delta = chronometer.tack();
        if (delta < GAME_LOOP_RATE)
            usleep(GAME_LOOP_RATE - delta);
    }
}

void Server::finish() {
    try {
        char c;
        do {
            std::cin >> c;
        } while (c != 'q');

        protocol.shutdown(SHUT_RDWR);
        active_game = false;
        keep_accepting = false;
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "[finish]: " << e.what() << std::endl;
        // Para evitar RC en el flujo de error
        std::cerr << oss.str();
    }

}

void Server::acceptClients() {
    try {
        while (keep_accepting) {
            Socket peer = protocol.accept();
            std::cout << "Acepta un cliente" << std::endl;
            auto *client = new ThClient(std::move(peer), protectedQueue, nextPlayerId, map.getRows(), map.getColumns(), terrain);
            map.buildConstructionCenter(nextPlayerId);
            client->start();
            clients.push(client);
            clients.clean();
            nextPlayerId++;
        }
    } catch(const std::exception &e) {
        // clients.clearAll(); leak si tenés una salida sin excepción. esto va en el destructor
        std::ostringstream oss;
        oss << "[aceptador]: " << e.what() << std::endl;
        // Para evitar RC en el flujo de error
        std::cout << oss.str();
        return;
    }
}

void Server::manageEvents() {
    ServerEvent *event = protectedQueue.pop();
    while (event != nullptr) {
        event->performEvent(map);
        delete event;
        event = protectedQueue.pop();
    }
    map.updateUnitsPosition();
    map.updateHarvestersStatus();
    map.unitCheck();
    Snapshot snapshot = createSnapshot();
    map.unitAttackReset();
    blockingQueue.push(snapshot);
}

void Server::broadCast() {
    // Si es una partida de 4, y uno se desconecta, debe terminar la partida?
    while (active_game) {
        try {
            Snapshot snapshot = blockingQueue.pop();
            if (!active_game) {
                return;
            }
            clients.broadCast(std::move(snapshot));  // Actualizo a todos los clientes
        } catch (std::exception &e) {
            std::ostringstream oss;
            oss << "[broadcast]: " << e.what() << std::endl;
            // Para evitar RC en el flujo de error
            std::cout << oss.str();
            clients.clean();
        }
    }
}

Snapshot Server::createSnapshot() {
    Snapshot snapshot;
    map.addSnapshotData(snapshot);

    return std::move(snapshot);
}
