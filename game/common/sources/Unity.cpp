#include <stack>
#include <utility>
#include "../headers/Unity.h"

Unity::Unity(int id, double hp, int range, int speed, coordenada_t coord) :
        Entity(id, hp), range(range), speed(speed), coord(std::move(coord)) {}

void Unity::setPath(std::stack<coordenada_t> _path) {
    this->path = std::move(_path);
}

coordenada_t Unity::getPosition() {
    return coord;
}
