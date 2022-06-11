#include "../headers/Server.h"

Server::Server(const std::string &host, int rows, int columns) :
    map(rows, columns), protocol(host), keep_accepting(true) {}

void Server::run() {
    std::thread acceptingThread(&Server::acceptClients, this);
    std::thread broadcastThread(&Server::broadCast, this);

    bool active_game = true;
    do {
        active_game = manageEvents();

    } while (active_game);

    acceptingThread.join();
    broadcastThread.join();
}

void Server::broadCast() {
    Event event(blockingQueue.pop());
    for (ThClient *client : clients) {
        client->sendEvent(event);
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

bool Server::manageEvents() {
    if (protectedQueue.empty())
        return false;

    Event event(protectedQueue.pop());
    blockingQueue.push(std::move(event));

    return true;
}
