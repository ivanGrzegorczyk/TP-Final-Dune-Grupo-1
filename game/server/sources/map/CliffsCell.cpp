#include "server/headers/map/CliffsCell.h"

CliffsCell::CliffsCell(coordenada_t coord) : ServerCell(coord) {}

int CliffsCell::ground() {
    return TERRAIN_CLIFFS;
}

unsigned int CliffsCell::harvest() {
    throw std::runtime_error("Cannot harvest on rocks");
}


