#include "../headers/Server.h"
#include "../../common/headers/Constantes.h"

Server::Server(const std::string &host, int rows, int columns) :
    map(rows, columns), protocol(host), keep_accepting(true), active_game(true) {}

void Server::run() {
    std::thread acceptingThread(&Server::acceptClients, this);
    std::thread broadcastThread(&Server::broadCast, this);
    std::thread finishThread(&Server::finish, this);

    auto t1 = std::chrono::system_clock::now();

    do {
        auto t2 = std::chrono::system_clock::now();
        auto delta = simDeltaTime(t1, t2);
        manageEvents();
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

void Server::broadCast() {
    while (active_game) {
        Event event(blockingQueue.pop());
        if (!active_game)
            return;  // TODO Salida temporal
        for (ThClient *client : clients) {
            client->sendEvent(event);
        }
    }
}

void Server::acceptClients() {
    try {
        while (keep_accepting) {
            Socket peer = protocol.accept();
            auto *client = new ThClient(std::move(peer), protectedQueue, map);
            client->start();
            clients.push_back(client);
        }
    } catch(const std::exception &e) {
        // TODO Manejar excepcion
    }
    cleanClients();
}

void Server::cleanClients() {
    clients.erase(std::remove_if(
            clients.begin(), clients.end(), cleanClient), clients.end());
}

bool Server::cleanClient(ThClient *client) {
    if (client->isDead()) {
        client->join();
        delete client;
        return true;
    }
    return false;
}

void Server::manageEvents() {
    Event event(protectedQueue.pop());
    blockingQueue.push(std::move(event));
}
