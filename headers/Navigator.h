#ifndef NAVIGATOR_H_
#define NAVIGATOR_H_

#include <unistd.h>
#include <cstdlib>

#include "ServerCell.h"
#include "Node.h"
#include "ServerMap.h"
#include "Node.h"

class Navigator {
private:
    std::vector<Node> openSet;
    std::vector<std::vector<Node>> nodeMap;
    Node current;

    void manageNeighbour(coordenada_t neighbour, coordenada_t end);
    std::stack<coordenada_t> reconstructPath(coordenada_t start);

    void mostrar();

public:
    Navigator() = delete;
    Navigator(std::vector<std::vector<ServerCell>> &map);

    std::stack<coordenada_t> A_star(coordenada_t start, coordenada_t end);
};

#endif  // NAVIGATOR_H_
