#include "../headers/ServerMap.h"

int main() {
    ServerMap mapa(25, 120);

    for (int i = 0; i < 24; i++) {
        mapa.map[i][10].ground = 'X';
    }

    for (int i = 1; i < 10; i++) {
        mapa.map[i][60].ground = 'X';
    }

    for (int i = 10; i < 25; i++) {
        mapa.map[i][80].ground = 'X';
    }

    mapa.map[18][80].ground = '.';

    for (int i = 11; i < 22; i++) {
        mapa.map[i][30].ground = 'X';
    }

    for (int i = 10; i < 119; i++) {
        mapa.map[10][i].ground = 'X';
    }

    mapa.A_star(coordenada_t {2, 2}, coordenada_t {8, 15});

    return 0;
}
