#include "server/headers/map/Node.h"

Node::Node() {
    this->id = {-1, -1};
    this->previous_id = {-1, -1};
    f = g = INFINITY;
    blocked = false;
}

Node::Node(coordenada_t id, int terrain, bool occupied) {
    this->id = id;
    this->previous_id = {-1, -1};
    blocked = terrain != TERRAIN_ROCKS || occupied;
    if (occupied) {
        std::cout << id.first << " " << id.second << std::endl;
    }
    f = g = INFINITY;
}

bool Node::isBlocked() const {
    return blocked;
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
