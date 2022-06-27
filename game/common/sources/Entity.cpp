#include "../headers/Entity.h"

#include <utility>

Entity::Entity(int playerId, int id, double HP, int type, coordenada_t coord) : playerId(playerId), id(id), HP(HP), type(type), coord(std::move(coord)) {}

int Entity::getType() const {
    return type;
}

int Entity::getId() const {
    return id;
}

coordenada_t Entity::getPosition() {
    return coord;
}

Entity::Entity() {}
