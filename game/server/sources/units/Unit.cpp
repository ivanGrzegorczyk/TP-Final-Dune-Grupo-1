#include <stack>
#include <utility>
#include "server/headers/units/Unit.h"

Unit::Unit(int id, unsigned int hp, unsigned int range,
           unsigned int speed, int type, unsigned int cost,
           coordenada_t coord) :
        Entity(id, hp, type, coord), range(range), speed(speed), cost(cost), target(0) {}

void Unit::setPath(std::stack<coordenada_t> _path) {
    this->path = std::move(_path);
}

coordenada_t Unit::relocate() {
    if (path.empty())
        return {-1, -1};

    coordenada_t free = coord;
    coord = path.top();
    path.pop();
    return free;
}

coordenada_t Unit::getNextPosition() {
    coordenada_t ret(-1, -1);
    if (!path.empty())
        ret = path.top();

    return ret;
}

void Unit::setPosition(coordenada_t newPosition) {
    this->coord = newPosition;
}

coordenada_t Unit::getGoal() {
    coordenada_t goal(-1, -1);
    while (!path.empty()) {
        goal = path.top();
        path.pop();
    }

    return std::move(goal);
}

bool Unit::isStill() {
    return path.empty();
}

unsigned int Unit::getRange() const {
    return range;
}

void Unit::setTarget(int _target) {
    this->target = _target;
}

bool Unit::hasTarget() {
    return target != 0;
}
