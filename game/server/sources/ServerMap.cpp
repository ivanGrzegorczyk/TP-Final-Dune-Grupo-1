#include "../headers/ServerMap.h"

ServerMap::ServerMap(int rows, int columns) :
map(rows, std::vector<ServerCell>(columns)) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j].id = {i, j};
        }
    }
}

std::stack<coordenada_t> ServerMap::A_star(
        coordenada_t start, coordenada_t end) {
    Navigator navigator(map);
    return navigator.A_star(start, end);
}

bool ServerMap::reposition(int id, coordenada_t goal) {
    try {
        if (unities.at(id)->getPosition() == goal)
            return false;

        unities.at(id)->setPath(
                A_star(unities.at(id)->getPosition(), goal));
        return true;  // TODO Revisar caso en el que no hay un camino posible
    } catch(const std::out_of_range &e) {
        return false;
    }
}
