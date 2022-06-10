#ifndef THCLIENT_H_
#define THCLIENT_H_

#include <atomic>
#include <string>

#include "../../common/headers/Thread.h"
#include "../../common/headers/Socket.h"

class ThClient: public Thread {
private:
    std::atomic<bool> keep_talking;
    std::atomic<bool> is_running;
    Socket peer;

protected:
    void run() override;

public:
    ThClient(Socket &&skt);

    bool isDead();
    void stop();

    ThClient(const ThClient&) = delete;
    ThClient& operator=(const ThClient&) = delete;
};

#endif  // THCLIENT_H_
