#include "../headers/Entity.h"

Entity::Entity(int id, double HP, int type) : id(id), HP(HP), type(type) {}

int Entity::getType() const {
    return type;
}
