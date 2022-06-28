#include "server/headers/map/RockCell.h"

RockCell::RockCell(coordenada_t coord) : ServerCell(coord) {}

int RockCell::ground() {
    return TERRAIN_ROCKS;
}

unsigned int RockCell::harvest() {
    throw std::runtime_error("Cannot harvest on rocks");
}

