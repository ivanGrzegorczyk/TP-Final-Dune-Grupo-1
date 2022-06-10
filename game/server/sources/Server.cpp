#include "../headers/Server.h"

Server::Server(const std::string &host, int rows, int columns) :
    map(rows, columns), socket(host.c_str()) {}

void Server::run() {


    bool active_game = true;
    do {
        active_game = manageEvents();

    } while (active_game);
}

void Server::acceptClients() {
    try {
        while (keep_accepting) {
            Socket peer = socket.accept();
            auto *client = new ThClient(std::move(peer));
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
    if (events.empty())
        return false;

    // Manages events

    return true;
}
