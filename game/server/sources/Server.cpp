#include <unistd.h>
#include <iostream>
#include <thread>
#include "../headers/Server.h"
#include "../../common/headers/Constantes.h"

Server::Server(const std::string &host, int rows, int columns) :
    map(rows, columns), protocol(host), keep_accepting(true), active_game(true), nextPlayerId(1) {}

void Server::run() {
    std::thread acceptingThread(&Server::acceptClients, this);
    std::thread broadcastThread(&Server::broadCast, this);
    std::thread finishThread(&Server::finish, this);

    auto t1 = std::chrono::system_clock::now();

    do {
        manageEvents();
        auto t2 = std::chrono::system_clock::now();
        auto delta = simDeltaTime(t1, t2);
        sleep(t1, t2, delta);
    } while (active_game);

    acceptingThread.join();
    broadcastThread.join();
    finishThread.join();
}

duration Server::simDeltaTime(chrono &t1, chrono &t2) {
    t2= std::chrono::system_clock::now();
    auto delta= t2 - t1;
    t1 = t2;

    return delta;
}

void Server::sleep(const chrono &t1, const chrono &t2, duration &delta) const {
    delta = t2 - t1;
    if (delta.count() < GAME_LOOP_RATE)
        usleep(GAME_LOOP_RATE - delta.count());
}

void Server::finish() {
    char c;
    do {
        std::cin >> c;
    } while (c != 'q');

    protocol.shutdown(SHUT_RDWR);
    active_game = false;
    keep_accepting = false;
}

void Server::acceptClients() {
    try {
        while (keep_accepting) {
            Socket peer = protocol.accept();
            auto *client = new ThClient(std::move(peer), protectedQueue, nextPlayerId);
            client->start();
            clients.push(client);
            nextPlayerId++;
        }
    } catch(const std::exception &e) {
        // TODO Manejar excepcion
    }
}

void Server::manageEvents() {
    ServerEvent *event = protectedQueue.pop();
    if (event != nullptr)
        event->performEvent(this);
}

void Server::broadCast() {
    while (active_game) {
        if (blockingQueue.pop()) {
            if (!active_game) {
                return;  // TODO Salida temporal
            }
            std::vector<uint16_t> snapshot = createSnapshot();
            clients.broadCast(snapshot);  // Actualizo a todos los clientes
        }
    }
}

void Server::repositionUnit(int playerId, int unitId, coordenada_t goal) {
    bool updateClient;
    updateClient = map.reposition(playerId, unitId, goal);
    blockingQueue.push(updateClient);
}

void Server::spawnUnit(int playerId, int unit) {
    map.spawnUnit(playerId, unit);
}

std::vector<uint16_t> Server::createSnapshot() {
    std::vector<uint16_t> snapshot;
    map.addUnitData(snapshot);
    return snapshot;
}
