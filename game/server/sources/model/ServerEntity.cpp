#include "server/headers/model/ServerEntity.h"

#include <utility>

ServerEntity::ServerEntity(int id, unsigned int HP, int type, coordenada_t coord) : id(id), HP(HP), type(type), coord(std::move(coord)) {}

int ServerEntity::getType() const {
    return type;
}

int ServerEntity::getId() const {
    return id;
}

coordenada_t ServerEntity::getPosition() {
    return coord;
}

bool ServerEntity::receiveDamage(unsigned int damage) {
    if (damage < HP) {
        HP -= damage;
    } else {
        HP = 0;
        return true;
    }

    return false;
}
