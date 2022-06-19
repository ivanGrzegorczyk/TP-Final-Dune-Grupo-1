#include "../headers/Navigator.h"

Navigator::Navigator(std::vector<std::vector<ServerCell *>> &map) : nodeMap(map.size(), std::vector<Node>(map.at(0).size())) {
    for (size_t i = 0; i < 50; i++) {
        for (size_t j = 0; j < 50; j++) {
            nodeMap[j][i] = Node(coordenada_t {j, i}, map[i][j]->ground());
        }
    }
}

void Navigator::manageNeighbour(coordenada_t neighbour, coordenada_t end) {
    int x = neighbour.first, y = neighbour.second;
    if (!nodeMap[x][y].isBlocked()) {
        double tentativeG = current.getG() + current.calculateG(neighbour);
        if (tentativeG < nodeMap[x][y].getG()) {
            nodeMap[x][y].previous_id = current.id;
            double heuristic = nodeMap[x][y].calculateH(end);
            nodeMap[x][y].setG(tentativeG);
            nodeMap[x][y].setF(tentativeG + heuristic);
            if (heuristic < closest.calculateH(end))
                closest = nodeMap[x][y];
            if (std::find(openSet.begin(), openSet.end(), nodeMap[x][y]) == openSet.end()) {
                openSet.push_back(nodeMap[x][y]);
            }
        }
    }
}

std::stack<coordenada_t> Navigator::reconstructPath(coordenada_t start) {
    std::stack<coordenada_t> path;
    int x = start.first, y = start.second;
    while (current.id.first != x || current.id.second != y) {
        path.push(current.id);
        current = nodeMap[current.previous_id.first][current.previous_id.second];
    }
    path.push(current.id);

    return path;
}

std::stack<coordenada_t> Navigator::A_star(coordenada_t start, coordenada_t end) {
    current = nodeMap[start.first][start.second];
    current.setG(0);
    current.setF(current.getG() + current.calculateH(end));
    closest = current;
    openSet.push_back(current);

    while (!openSet.empty()) {
        // Puedo usar sort porque sobrecargue el operador <
        std::sort(openSet.begin(), openSet.end());
        current = openSet.at(0);  // El que tiene menor f

        if (current.id == end) {
            return reconstructPath(start);
        }

        openSet.erase(std::remove(openSet.begin(), openSet.end(), current), openSet.end());
        // Recorro los vecinos
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // Reviso que el vecino se encuentre dentro del mapa
                if (current.id.first + i >= 0 && current.id.second + j >= 0
                    && current.id.first + i < nodeMap.size()
                    && current.id.second + j < nodeMap.at(0).size() && !(i == 0 && j == 0)) {
                    int x = current.id.first + i;
                    int y = current.id.second + j;
                    manageNeighbour(coordenada_t {x, y}, end);
                }
            }
        }
    }

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            nodeMap[i][j].previous_id = {-1, -1};
            nodeMap[i][j].setF(INFINITY);
            nodeMap[i][j].setG(INFINITY);
        }
    }

    return A_star(start, closest.id);
}
