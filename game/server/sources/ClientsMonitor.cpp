#include "../headers/ClientsMonitor.h"

ClientsMonitor::~ClientsMonitor() {
    clean();
}

void ClientsMonitor::push(ThClient *client) {
    std::lock_guard<std::mutex> lock(mutex);
    clients.push_back(client);
    clean();
}

void ClientsMonitor::clean() {
    clients.erase(std::remove_if(
            clients.begin(), clients.end(), cleanClient), clients.end());
}

bool ClientsMonitor::cleanClient(ThClient *client) {
    if (client->isDead()) {
        client->join();
        delete client;
        return true;
    }
    return false;
}

void ClientsMonitor::broadCast() {
    std::lock_guard<std::mutex> lock(mutex);
    // TODO Mando la foto del mundo
}
