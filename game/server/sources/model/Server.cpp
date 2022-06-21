#include <unistd.h>
#include <iostream>
#include <thread>
#include "server/headers/model/Server.h"
#include "common/headers/Chronometer.h"

Server::Server(const std::string &host) :
protocol(host), keep_accepting(true), active_game(true), nextPlayerId(1) {
    map.initializeTerrain(terrain);
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
    uint64_t t1 = chronometer.now();

    while (active_game) {
        manageEvents();  // Acá se manejan los eventos de la cola protegida
        uint64_t t2 = chronometer.now();
        long rest = GAME_LOOP_RATE - (long)(t2 - t1);
        std::cout << rest << std::endl; 
        if (rest < 0) {
            uint64_t behind =- rest;
            uint64_t lost = GAME_LOOP_RATE - behind % GAME_LOOP_RATE;
            t1 += lost;
        } else {
            usleep(rest);
        }

        t1 += GAME_LOOP_RATE;
    }
}

void Server::finish() {
    char c;
    do {
        std::cin >> c;
    } while (c != 'q');

    protocol.shutdown(SHUT_RDWR);
    active_game = false;
    keep_accepting = false;
    blockingQueue.stop();
}

void Server::acceptClients() {
    try {
        while (keep_accepting) {
            Socket peer = protocol.accept();
            std::cout << "Acepta un cliente" << std::endl;
            auto *client = new ThClient(std::move(peer), protectedQueue, nextPlayerId, map.getRows(), map.getColumns(), terrain);
            client->start();
            clients.push(client);
            clients.clean();
            nextPlayerId++;
        }
    } catch(const std::exception &e) {
        clients.clearAll();
        std::cout << "Catchea en el acceptClients y sale" << std::endl;
        return;
    }
}

void Server::manageEvents() {
    ServerEvent *event = protectedQueue.pop();
    while (event != nullptr) {
        event->performEvent(map);
        event = protectedQueue.pop();
    }
    map.updateUnitsPosition();
    std::vector<uint16_t> snapshot(createSnapshot());
    blockingQueue.push(snapshot);
}

void Server::broadCast() {
    while (active_game) {
        std::vector<uint16_t> snapshot = blockingQueue.pop();
        if (!active_game) {
            return;
        }
        clients.broadCast(snapshot);  // Actualizo a todos los clientes
    }
}

std::vector<uint16_t> Server::createSnapshot() {
    std::vector<uint16_t> snapshot;
    map.addSnapshotData(snapshot);
    uint16_t size = snapshot.size();
    snapshot.insert(snapshot.begin(), size);
    return snapshot;
}
