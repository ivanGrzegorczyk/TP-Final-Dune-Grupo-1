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

void ServerMap::mostrar(std::stack<coordenada_t> path) {
    size_t size = path.size();
    for (size_t i = 0; i < size; i++) {
        map[path.top().first][path.top().second].ground = 'o';
        path.pop();
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (map[i][j].ground == '*')
                map[i][j].ground = '.';
            std::cout << map[i][j].ground;
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void ServerMap::A_star(coordenada_t start, coordenada_t end) {
    Navigator navigator(map);
    std::stack<coordenada_t> path = navigator.A_star(start, end);
    usleep(1000);
    system("clear");
    mostrar(path);
}
