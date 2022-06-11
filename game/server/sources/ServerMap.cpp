#include <unistd.h>

#include "../headers/ServerMap.h"

ServerMap::ServerMap(int rows, int columns) : rows(rows), columns(columns),
    map(rows, std::vector<ServerCell>(columns)) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j].id = {i, j};
        }
    }
}

std::stack<coordenada_t> ServerMap::A_star(coordenada_t start, coordenada_t end) {
    Navigator navigator(map);
    return navigator.A_star(start, end);
}
