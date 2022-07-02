#include "server/headers/model/Lobby.h"
#include "server/headers/model/ThCLient.h"

void Lobby::joinPlayer(Socket &&socket, std::vector<Room> &rooms) {
    auto *client = new ThClient(std::move(socket));
    client->beginSynchroCom(rooms);
    clients.push_back(client);
    clean();
}

void Lobby::clean() {
    clients.erase(std::remove_if(
            clients.begin(), clients.end(),
            cleanClient), clients.end());
}

bool Lobby::cleanClient(ThClient *client) {
    if (client->isDead()) {
        client->join();
        delete client;
        return true;
    }
    return false;
}
