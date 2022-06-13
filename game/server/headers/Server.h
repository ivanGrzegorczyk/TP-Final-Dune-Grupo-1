#ifndef SERVER_H_
#define SERVER_H_

#include <atomic>
#include <list>
#include <chrono>
#include "ServerProtocol.h"
#include "ServerMap.h"
#include "../../common/headers/BlockingQueue.h"
#include "../../common/headers/ProtectedQueue.h"

class ServerEvent;

#include "ClientsMonitor.h"
#include "ServerEvent.h"

typedef std::chrono::time_point<std::chrono::system_clock> chrono;
typedef std::chrono::duration<double, std::milli> duration;

class Server {
private:
    ServerMap map;
    ProtectedQueue<ServerEvent *> protectedQueue;
    BlockingQueue<bool> blockingQueue;
    ServerProtocol protocol;
    std::atomic<bool> keep_accepting;
    std::atomic<bool> active_game;
    ClientsMonitor clients;
    int nextPlayerId;

    void finish();
    void broadCast();
    void sleep(const chrono &t1, const chrono &t2, duration &delta) const;
    void acceptClients();
    void manageEvents();

public:

    Server(const std::string &host, int rows, int columns);
    // Gameloop
    void run();

    void repositionUnity(int id, coordenada_t goal);

    static duration simDeltaTime(chrono &t1, chrono &t2);
};

#endif  // SERVER_H_
