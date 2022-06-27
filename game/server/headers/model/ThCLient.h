#ifndef THCLIENT_H_
#define THCLIENT_H_

#include <atomic>
#include "ServerProtocol.h"
#include "common/headers/Thread.h"
#include "common/headers/ProtectedQueue.h"
#include "server/headers/events/ServerEvent.h"
#include "Snapshot.h"

class ThClient: public Thread {
private:
    std::atomic<bool> keep_talking;
    std::atomic<bool> is_running;
    ServerProtocol protocol;
    ProtectedQueue<ServerEvent *> &protectedQueue;
    int playerId;
    int rows;
    int columns;
    std::vector<uint8_t> terrain;

    void manageCommand(int command);
    void repositionUnit();
    void spawnUnit();
    void createBuilding();

protected:

    void run() override;
public:

    ThClient(Socket &&peer, ProtectedQueue<ServerEvent *> &protectedQueue, int id, int rows, int columns, std::vector<uint8_t> &terrain);
    bool isDead();

    void stop();

    void sendSnapshot(Snapshot &snapshot);
    ThClient(const ThClient&) = delete;

    ThClient& operator=(const ThClient&) = delete;
};

#endif  // THCLIENT_H_
