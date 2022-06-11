#ifndef SERVER_H_
#define SERVER_H_

#include <atomic>
#include <list>

#include "ThCLient.h"
#include "ServerMap.h"
#include "ServerProtocol.h"
#include "../../common/headers/Socket.h"
#include "../../common/headers/BlockingQueue.h"
#include "../../common/headers/ProtectedQueue.h"

typedef std::chrono::time_point<std::chrono::system_clock> chrono;
typedef std::chrono::duration<double, std::milli> duration;

class Server {
private:
    ServerMap map;
    ProtectedQueue protectedQueue;
    BlockingQueue blockingQueue;
    ServerProtocol protocol;
    std::atomic<bool> keep_accepting;
    std::atomic<bool> active_game;
    std::list<ThClient *> clients;
    Event event_to_send;

    void finish();
    void broadCast();
    void sleep(const chrono &t1, const chrono &t2, duration &delta) const;
    void acceptClients();
    void cleanClients();
    static bool cleanClient(ThClient *client);

public:
    Server(const std::string &host, int rows, int columns);

    // Gameloop
    void run();

    void manageEvents();

    static duration simDeltaTime(chrono &t1, chrono &t2) ;
};

#endif  // SERVER_H_
