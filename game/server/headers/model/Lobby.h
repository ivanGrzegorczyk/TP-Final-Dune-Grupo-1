#ifndef LOBBY_H_
#define LOBBY_H_

#include <vector>
#include <list>
#include "common/headers/Socket.h"
#include "Room.h"
#include "ThCLient.h"

class Lobby {
private:
    std::list<ThClient *> clients;

    void clean();
    static bool cleanClient(ThClient *client);

public:
    Lobby() = default;
    ~Lobby() = default;

    void joinPlayer(Socket &&socket, std::vector<Room> &rooms);

    Lobby(const Lobby&) = delete;
    Lobby& operator=(const Lobby&) = delete;
};

#endif  // LOBBY_H_
