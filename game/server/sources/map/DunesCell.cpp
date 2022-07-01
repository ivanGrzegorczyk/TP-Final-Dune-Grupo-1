#include "server/headers/map/DunesCell.h"

DunesCell::DunesCell(coordenada_t coord) : ServerCell(coord) {}

int DunesCell::ground() {
    return TERRAIN_DUNES;
}

unsigned int DunesCell::harvest() {
    throw std::runtime_error("Cannot harvest on Dunes");
}




