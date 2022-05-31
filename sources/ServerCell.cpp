#include "../headers/ServerCell.h"

ServerCell::ServerCell() {
    id = {0, 0};
    ground = '.';
}

ServerCell::ServerCell(coordenada_t coord) {
    id = coord;
    ground = '.';
}
