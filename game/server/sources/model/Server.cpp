#include <unistd.h>
#include <iostream>
#include <thread>
#include "server/headers/model/Server.h"
#include "common/headers/Chronometer.h"

Server::Server(const std::string &host, int rows, int columns) :
    map(rows, columns), protocol(host), keep_accepting(true), active_game(true), nextPlayerId(1) {
    // TODO las dimensiones del mapa están hardcodeadas en 50x50 por ahora
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
    auto t1 = chronometer.tick();
    while (active_game) {
        auto test1 = chronometer.tick();
        manageEvents();  // Acá se manejan los eventos de la cola protegida
        auto t2 = chronometer.tick();
        auto rest =  - (t2 - t1);
        if (rest < 0) {
            auto behind = -rest;
            rest = 1 / 30 - behind % (1 / 30);
            auto lost = behind + rest;
            t1 += lost;
        }

        usleep(rest);
        t1 += 1 / 30;
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
            auto *client = new ThClient(std::move(peer), protectedQueue, nextPlayerId, terrain);
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
