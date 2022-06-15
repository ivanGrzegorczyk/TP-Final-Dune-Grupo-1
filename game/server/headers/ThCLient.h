#ifndef THCLIENT_H_
#define THCLIENT_H_

#include <atomic>
#include <string>

#include "../../common/headers/Thread.h"
#include "../../common/headers/Socket.h"
#include "ServerProtocol.h"
#include "ServerMap.h"
#include "../../common/headers/ProtectedQueue.h"

class ThClient: public Thread {
private:
    std::atomic<bool> keep_talking;
    std::atomic<bool> is_running;
    ServerProtocol protocol;
    ProtectedQueue &protectedQueue;
    ServerMap &map;

    void searchPath();

protected:
    void run() override;

public:
    ThClient(Socket &&peer, ProtectedQueue &protectedQueue, ServerMap &map);

    bool isDead();
    void stop();

    void sendEvent(Event &event);

    ThClient(const ThClient&) = delete;
    ThClient& operator=(const ThClient&) = delete;
};

#endif  // THCLIENT_H_
