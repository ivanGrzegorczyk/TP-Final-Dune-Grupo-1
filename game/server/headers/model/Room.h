#ifndef ROOM_H_
#define ROOM_H_

#include <vector>
#include <string>
#include "Player.h"

class Room {
private:
    unsigned int required;
    std::string name;
    std::vector<Player> players;

public:
    Room(unsigned int required, std::string  name);
    ~Room() = default;

    bool isFull();
    unsigned int getRequired() const;
    unsigned int getCurrent();
    std::string getName();
};

#endif  // ROOM_H_
