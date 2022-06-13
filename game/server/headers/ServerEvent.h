#ifndef SERVEREVENT_H_
#define SERVEREVENT_H_

#include "Server.h"
class Server;

class ServerEvent {
public:
    virtual void performEvent(Server *server) = 0;
};

#endif  // SERVEREVENT_H_
