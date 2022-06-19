#include "server/headers/model/map/SandCell.h"

SandCell::SandCell(coordenada_t coord, unsigned int spice) : ServerCell(coord), spice(spice) {}

bool SandCell::receiveUnit() {
    return false;
}

int SandCell::ground() {
    return TERRAIN_SAND;
}
