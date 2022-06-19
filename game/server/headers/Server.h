#ifndef SERVER_H_
#define SERVER_H_

#include <atomic>
#include <list>
#include <chrono>

#include "ServerProtocol.h"
#include "server/headers/model/map/ServerMap.h"
#include "../../common/headers/BlockingQueue.h"
#include "../../common/headers/ProtectedQueue.h"
#include "ClientsMonitor.h"
#include "events/ServerEvent.h"

class Server {
private:
    ServerMap map;
    ProtectedQueue<ServerEvent *> protectedQueue;
    BlockingQueue<std::vector<uint16_t>> blockingQueue;
    ServerProtocol protocol;
    std::atomic<bool> keep_accepting;
    std::atomic<bool> active_game;
    ClientsMonitor clients;
    int nextPlayerId;
    std::vector<uint8_t> terrain;

    void finish();
    void broadCast();
    void acceptClients();
    void manageEvents();

public:

    Server(const std::string &host, int rows, int columns);
    // Gameloop
    void run();

    std::vector<uint16_t> createSnapshot();

};

#endif  // SERVER_H_
