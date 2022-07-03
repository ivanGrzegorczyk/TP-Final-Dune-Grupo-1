#include <stack>
#include <utility>
#include "server/headers/units/Unit.h"

Unit::Unit(int id, unsigned int hp, unsigned int range,
           unsigned int speed, int type, unsigned int cost, Weapon * weapon,
           coordenada_t coord) :
        Entity(id, hp, type, coord), range(range), speed(speed), cost(cost), weapon(weapon), target(0, 0) {}

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

void Unit::setPosition(coordenada_t newPosition) {
    this->coord = newPosition;
}

bool Unit::isStill() {
    return path.empty();
}

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
    return weapon->attack(enemy);
}

std::pair<int, int> Unit::getTarget() {
    return target;
}

void Unit::stopMoving() {
    for (int i = 0; i < path.size(); i++)
        path.pop();
}

bool Unit::receiveDamage(unsigned int damage) {
    if (damage < HP) {
        HP -= damage;
    } else {
      HP = 0;
      return true;
    }

    return false;
}
