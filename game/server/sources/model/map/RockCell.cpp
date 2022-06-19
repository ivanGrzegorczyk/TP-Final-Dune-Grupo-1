#include "server/headers/model/map/RockCell.h"

RockCell::RockCell(coordenada_t coord) : ServerCell(coord) {}

bool RockCell::receiveUnit() {
    return false;
}

int RockCell::ground() {
    return TERRAIN_ROCKS;
}

