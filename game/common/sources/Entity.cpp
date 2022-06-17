#include "../headers/Entity.h"

#include <utility>

Entity::Entity(int id, int HP, int type, coordenada_t coord) : id(id), HP(HP), type(type), coord(std::move(coord)) {}

int Entity::getType() const {
    return type;
}

coordenada_t Entity::getPosition() {
    return coord;
}
