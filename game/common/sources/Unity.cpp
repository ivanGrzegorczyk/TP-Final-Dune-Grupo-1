#include <stack>
#include <utility>
#include "../headers/Units.h"

Units::Units(int id, double hp, int range, int speed, int type, coordenada_t coord) :
        Entity(id, hp, type), range(range), speed(speed), coord(std::move(coord)) {}

void Units::setPath(std::stack<coordenada_t> _path) {
    this->path = std::move(_path);
}

coordenada_t Units::getPosition() {
    return coord;
}

bool Units::relocate() {
    if (path.empty())
        return false;

    coord = path.top();
    path.pop();
    return true;
}

void Units::setPosition(coordenada_t newPosition) {
    this->coord = newPosition;
}
