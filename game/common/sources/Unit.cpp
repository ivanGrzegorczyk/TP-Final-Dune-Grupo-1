#include <stack>
#include <utility>
#include "../headers/Unit.h"

Unit::Unit(int id, double hp, int range, int speed, int type, coordenada_t coord) :
        Entity(id, hp, type, coord), range(range), speed(speed) {}

void Unit::setPath(std::stack<coordenada_t> _path) {
    this->path = std::move(_path);
}

bool Unit::relocate() {
    if (path.empty())
        return false;

    coord = path.top();
    path.pop();
    return true;
}

void Unit::setPosition(coordenada_t newPosition) {
    this->coord = newPosition;
}
