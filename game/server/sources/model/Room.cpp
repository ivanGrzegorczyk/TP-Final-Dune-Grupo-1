#include "server/headers/model/Room.h"

#include <utility>

Room::Room(unsigned int required, std::string  name) :
        required(required), name(std::move(name)) {
    players.resize(required);
}

bool Room::isFull() {
    return players.size() == required;
}

unsigned int Room::getRequired() const {
    return required;
}

unsigned int Room::getCurrent() {
    return players.size();
}

std::string Room::getName() {
    return name;
};
