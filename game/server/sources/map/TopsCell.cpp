#include "server/headers/map/TopsCell.h"

TopsCell::TopsCell(coordenada_t coord) : ServerCell(coord) {}

int TopsCell::ground() {
    return TERRAIN_TOPS;
}

unsigned int TopsCell::harvest() {
    throw std::runtime_error("Cannot harvest on tops");
}

