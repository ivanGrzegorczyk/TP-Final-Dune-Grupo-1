#include <stack>
#include <utility>
#include "server/headers/units/Unit.h"

Unit::Unit(int playerId, int id, double hp, int range, int speed, int type, coordenada_t coord) :
        Entity(playerId, id, hp, type, coord), range(range), speed(speed) {}

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
