#include "../headers/ServerCell.h"

ServerCell::ServerCell() {
    coords = {0, 0};
    ground = TERRAIN_ROCKS;
    building = nullptr;
}

ServerCell::ServerCell(coordenada_t coord) {
    coords = coord;
    ground = TERRAIN_ROCKS;
    building = nullptr;
}
