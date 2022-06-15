#ifndef NODE_H_
#define NODE_H_

#include "ServerCell.h"

#define COST_STRAIGHT 10
#define COST_DIAGONAL 14

class Node {
private:
    double f, g;  // Valores algoritmo A*

public:
    ServerCell *cell;

    coordenada_t id;
    coordenada_t previous_id;

    Node();
    explicit Node(coordenada_t id, ServerCell &cell);

    double getG() const;
    void setG(double g);
    void setF(double f);

    bool blocked() const;

    double calculateH(coordenada_t end) const;
    double calculateG(coordenada_t neighbour) const;

    bool operator==(const Node &other) const;
    bool operator<(const Node &other) const;
};

#endif  // NODE_H_
