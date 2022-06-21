#include "server/headers/map/ServerCell.h"

ServerCell::ServerCell() {
    coords = {0, 0};
    building = nullptr;
}

ServerCell::ServerCell(coordenada_t coord) {
    coords = coord;
    building = nullptr;
}
