#ifndef NODE_H_
#define NODE_H_

#include "server/headers/map/ServerCell.h"

#define COST_STRAIGHT 10
#define COST_DIAGONAL 14

class Node {
private:
    double f, g;  // Valores algoritmo A*
    bool blocked;

public:
    coordenada_t id;
    coordenada_t previous_id;

    Node();
    explicit Node(coordenada_t id, int terrain, bool occupied);

    double getG() const;
    void setG(double g);
    void setF(double f);

    bool isBlocked() const;

    double calculateH(coordenada_t end) const;
    double calculateG(coordenada_t neighbour) const;

    bool operator==(const Node &other) const;
    bool operator<(const Node &other) const;
};

#endif  // NODE_H_
