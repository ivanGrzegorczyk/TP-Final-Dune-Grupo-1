#include <stack>
#include <utility>
#include "server/headers/units/Unit.h"

Unit::Unit(int id, unsigned int hp, unsigned int range,
           unsigned int speed, int type, unsigned int cost,
           coordenada_t coord) :
        MovableEntity(id, hp, type, speed, coord), range(range), cost(cost), target(0) {}

unsigned int Unit::getRange() const {
    return range;
}

void Unit::setTarget(int _target) {
    this->target = _target;
}

bool Unit::hasTarget() {
    return target != 0;
}
