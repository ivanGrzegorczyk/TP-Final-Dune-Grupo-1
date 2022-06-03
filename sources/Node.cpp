#include "../headers/Node.h"

Node::Node() {
    this->id = {-1, -1};
    this->previous_id = {-1, -1};
    f = g = INFINITY;
    this->cell = nullptr;
}

Node::Node(coordenada_t id, ServerCell &cell) {
    this->id = id;
    this->previous_id = {-1, -1};
    this->cell = &cell;
    f = g = INFINITY;
}

bool Node::blocked() const {
    return (cell->ground == 'X');
}

bool Node::operator==(const Node &other) const {
    return (this->id == other.id);
}

bool Node::operator<(const Node &other) const {
    return this->f < other.f;
}

double Node::getG() const {
    return g;
}

void Node::setG(double g) {
    this->g = g;
}

void Node::setF(double f) {
    this->f = f;
}

double Node::calculateH(coordenada_t end) const {
    int x = end.first, y = end.second;
    return std::sqrt(std::pow(x - this->id.first, 2)
                     + std::pow(y - this->id.second, 2) * 1.0);
}

double Node::calculateG(coordenada_t neighbour) const {
    int x = neighbour.first, y = neighbour.second;
    if ((x == this->id.first + 1 && y == this->id.second + 1)
        || (x == this->id.first - 1 && y == this->id.second - 1)
        || (x == this->id.first + 1 && y == this->id.second - 1)
        || (x == this->id.first - 1 && y == this->id.second + 1)) {
        return COST_DIAGONAL;
    } else {
        return COST_STRAIGHT;
    }
}