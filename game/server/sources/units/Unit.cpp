#include <stack>
#include <utility>
#include "server/headers/units/Unit.h"

Unit::Unit(int id, unsigned int hp, unsigned int range,
           unsigned int speed, int type, unsigned int cost, Weapon * weapon,
           coordenada_t coord) :
        MovableEntity(id, hp, type, speed, coord), range(range),
        cost(cost), weapon(weapon), target(0, 0), attacking(false) {}

Unit::Unit(int id, unsigned int hp, unsigned int range,
           unsigned int speed, int type, unsigned int cost, Weapon * weapon,
           coordenada_t coord, bool attacking) :
        MovableEntity(id, hp, type, speed, coord), range(range),
        cost(cost), weapon(weapon), target(0, 0), attacking(attacking) {}

unsigned int Unit::getRange() const {
    return range;
}

void Unit::setTarget(int enemyId, int _target) {
    if (_target != 0)
        this->target = {enemyId, _target};
    else
        this->target = {0, 0};
}

bool Unit::hasTarget() const {
    return target.second != 0;
}

bool Unit::attack(std::shared_ptr<Unit> &enemy) {
    return weapon->attack(enemy, attacking);
}

std::pair<int, int> Unit::getTarget() {
    return target;
}

void Unit::stopMoving() {
    for (int i = 0; i < path.size(); i++)
        path.pop();
}

bool Unit::isAttacking() const {
    return attacking;
}

void Unit::stopAttacking() {
    attacking = false;
}
