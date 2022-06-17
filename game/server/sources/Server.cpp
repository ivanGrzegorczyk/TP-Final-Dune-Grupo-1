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
    std::thread finishThread(&Server::finish, this);  // TODO Multiples partidas

    do {
        manageEvents();
        usleep(10000000.0f/25.0f);  // TODO Poner el tiempo bien
    } while (active_game);

    acceptingThread.join();
    broadcastThread.join();
    finishThread.join();
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
            auto *client = new ThClient(std::move(peer), protectedQueue, nextPlayerId);
            client->start();
            clients.push(client);
            nextPlayerId++;
        }
    } catch(const std::exception &e) {
        // TODO Manejar excepcion
        std::cout << "Catchea en el acceptClients y sale" << std::endl;
        return;
    }
}

void Server::manageEvents() {
    ServerEvent *event = protectedQueue.pop();
    if (event != nullptr) {
        event->performEvent(map);
        blockingQueue.push(createSnapshot());
    }
    if (map.updateUnitPositions()) {
        blockingQueue.push(createSnapshot());
    }
}

void Server::broadCast() {
    while (active_game) {
        std::vector<uint16_t> snapshot = blockingQueue.pop();
        if (!active_game) {
            return;  // TODO Salida temporal
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
