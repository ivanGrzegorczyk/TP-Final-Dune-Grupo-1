#ifndef THCLIENT_H_
#define THCLIENT_H_

#include <atomic>
#include "ServerProtocol.h"
#include "../../common/headers/Thread.h"
#include "../../common/headers/ProtectedQueue.h"

class ServerEvent;
#include "ServerEvent.h"

class ThClient: public Thread {
private:
    std::atomic<bool> keep_talking;
    std::atomic<bool> is_running;
    ServerProtocol protocol;
    ProtectedQueue<ServerEvent *> &protectedQueue;
    int playerId;

    void manageCommand(int command);
    void repositionUnit();
    void spawnUnit();

protected:
    void run() override;

public:
    ThClient(Socket &&peer, ProtectedQueue<ServerEvent *> &protectedQueue, int id);

    bool isDead();
    void stop();

    ThClient(const ThClient&) = delete;
    ThClient& operator=(const ThClient&) = delete;
};

#endif  // THCLIENT_H_
