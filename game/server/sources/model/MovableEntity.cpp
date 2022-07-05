#include "server/headers/model/MovableEntity.h"

coordenada_t MovableEntity::getGoal() {
    coordenada_t goal(-1, -1);
    while (!path.empty()) {
        goal = path.top();
        path.pop();
    }

    return std::move(goal);
}

void MovableEntity::setPath(std::stack<coordenada_t> _path) {
    this->path = std::move(_path);
}

coordenada_t MovableEntity::relocate() {
    if (path.empty())
        return {-1, -1};

    coordenada_t free = coord;
    coord = path.top();
    path.pop();
    return free;
}

coordenada_t MovableEntity::getNextPosition() {
    coordenada_t ret(-1, -1);
    if (!path.empty())
        ret = path.top();

    return ret;
}

bool MovableEntity::isStill() {
    return path.empty();
}

MovableEntity::MovableEntity(int id, unsigned int hp, int type,
                             unsigned int speed, coordenada_t coord) :
                             ServerEntity(id, hp, type, coord), speed(speed) {}

