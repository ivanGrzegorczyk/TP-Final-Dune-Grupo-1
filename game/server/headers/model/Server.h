#ifndef SERVER_H_
#define SERVER_H_

#include <atomic>
#include <list>
#include <chrono>

#include "ServerProtocol.h"
#include "server/headers/map/ServerMap.h"
#include "common/headers/BlockingQueue.h"
#include "common/headers/ProtectedQueue.h"
#include "ClientsMonitor.h"
#include "server/headers/events/ServerEvent.h"
#include "Snapshot.h"

class Server {
private:
    ServerMap map;
    ProtectedQueue<ServerEvent *> protectedQueue;
    BlockingQueue<Snapshot> blockingQueue;
    ServerProtocol protocol;
    std::atomic<bool> keep_accepting;
    std::atomic<bool> active_game;
    ClientsMonitor clients;
    std::vector<uint8_t> terrain;

    void finish();
    void broadCast();
    void acceptClients();
    void manageEvents();
    void gameLoop();

public:

    explicit Server(const std::string &port);
    ~Server();
    // Gameloop
    void run();

    Snapshot createSnapshot();

};

#endif  // SERVER_H_
