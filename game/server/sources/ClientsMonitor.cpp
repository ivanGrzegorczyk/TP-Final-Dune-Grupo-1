#include "../headers/ThCLient.h"
#include "../headers/ClientsMonitor.h"

ClientsMonitor::~ClientsMonitor() {
    clean();
}

void ClientsMonitor::push(ThClient *client) {
    std::lock_guard<std::mutex> lock(mutex);
    clients.push_back(client);
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

void ClientsMonitor::clearAll() {
    std::lock_guard<std::mutex> lock(mutex);
    for (ThClient *client : clients) {
        client->stop();
        client->join();
        delete client;
    }
    clients.clear();
}

void ClientsMonitor::broadCast(const std::vector<uint16_t> &snapshot) {
    std::lock_guard<std::mutex> lock(mutex);
    for (ThClient *client : clients) {
        client->sendSnapshot(snapshot);
    }
}
