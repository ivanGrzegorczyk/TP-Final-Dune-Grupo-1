#include "../headers/Navigator.h"

Navigator::Navigator(std::vector<std::vector<ServerCell>> &map) : nodeMap(map.size(), std::vector<Node>(map.at(0).size())) {
    size_t filas = map.size();
    size_t columnas = map.at(0).size();

    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            nodeMap[i][j] = Node(coordenada_t {i, j}, map[i][j]);
        }
    }
}
void Navigator::mostrar() {
    for (int i = 0; i < nodeMap.size(); i++) {
        for (int j = 0; j < nodeMap.at(0).size(); j++) {
            std::cout << nodeMap[i][j].cell->ground;
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}


void Navigator::manageNeighbour(coordenada_t neighbour, coordenada_t end) {
    int x = neighbour.first, y = neighbour.second;
    if (!nodeMap[x][y].blocked()) {
        double tentativeG = current.getG() + current.calculateG(neighbour);
        if (tentativeG < nodeMap[x][y].getG()) {
            nodeMap[x][y].previous_id = current.id;
            nodeMap[x][y].setG(tentativeG);
            nodeMap[x][y].setF(tentativeG + nodeMap[x][y].calculateH(end));
            if (std::find(openSet.begin(), openSet.end(), nodeMap[x][y]) == openSet.end()) {
                openSet.push_back(nodeMap[x][y]);
                nodeMap[x][y].cell->ground = '*';  // Para imprimir las celdas que se analizan
                usleep(1000);
                system("clear");
                mostrar();
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

    std::cout << "\nGOAL NOT FOUND" << std::endl;
    return {};
}
