#include <stack>
#include <utility>
#include "../headers/Units.h"

Units::Units(int id, double hp, int range, int speed, coordenada_t coord) :
        Entity(id, hp), range(range), speed(speed), coord(std::move(coord)) {}

void Units::setPath(std::stack<coordenada_t> _path) {
    this->path = std::move(_path);
}

coordenada_t Units::getPosition() {
    return coord;
}

void Units::relocate() {
    if (path.empty())
        return;

    coord = path.top();
    path.pop();
}
