#ifndef SERVEREVENT_H_
#define SERVEREVENT_H_

class Server;
#include "Server.h"

class ServerEvent {
public:
    int playerId;

    explicit ServerEvent(int playerId) : playerId(playerId) {}

    virtual void performEvent(Server *server) = 0;
};

#endif  // SERVEREVENT_H_
