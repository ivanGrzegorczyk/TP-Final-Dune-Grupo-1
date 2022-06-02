#include "../headers/ServerCell.h"

ServerCell::ServerCell() {
    id = {0, 0};
    ground = '.';
    building = nullptr;
}

ServerCell::ServerCell(coordenada_t coord) {
    id = coord;
    ground = '.';
    building = nullptr;
}
