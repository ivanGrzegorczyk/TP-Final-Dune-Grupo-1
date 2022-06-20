#include "server/headers/map/SandCell.h"

SandCell::SandCell(coordenada_t coord, unsigned int spice) : ServerCell(coord), spice(spice) {}

int SandCell::ground() {
    return TERRAIN_SAND;
}

unsigned int SandCell::harvest() {
    if (spice <= 0)
        throw std::runtime_error("No spice on cell");

    unsigned int harvested;
    if (spice < 200) {
        harvested = spice;
        spice = 0;
    } else {
        spice -= 200;
        harvested = 200;
    }

    return harvested;
}
