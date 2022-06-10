#ifndef SERVER_H_
#define SERVER_H_

#include <atomic>
#include <list>

#include "../../common/headers/ProtectedQueue.h"
#include "../../common/headers/Socket.h"
#include "ThCLient.h"
#include "ServerMap.h"
#include "ServerProtocol.h"

class Server {
private:
    ServerMap map;
    ProtectedQueue events;
    ServerProtocol protocol;
    std::atomic<bool> keep_accepting;
    std::list<ThClient *> clients;

    void acceptClients();
    void cleanClients();
    static bool cleanClient(ThClient *client);

public:
    Server(const std::string &host, int rows, int columns);

    // Gameloop
    void run();

    bool manageEvents();
};

#endif  // SERVER_H_
