#ifndef SERVEREVENT_H_
#define SERVEREVENT_H_

#include "../ServerMap.h"
#include "../../../common/headers/BlockingQueue.h"

class ServerEvent {
public:
    int playerId;

    explicit ServerEvent(int playerId) : playerId(playerId) {}

    virtual void performEvent(ServerMap &map) = 0;
};

#endif  // SERVEREVENT_H_
