#include "server/headers/map/SandCell.h"

#define HARVEST_TIME 1000000 // 1 segundo cosecha 10

SandCell::SandCell(coordenada_t coord, unsigned int spice) : ServerCell(coord), spice(spice) {}

int SandCell::ground() {
    return TERRAIN_SAND;
}

unsigned int SandCell::harvest() {
    if (spice <= 0)
        throw std::runtime_error("No spice on cell");

    if (chronometer.tack() < HARVEST_TIME)
        return 0;

    unsigned int harvested;
    if (spice < 10) {
        harvested = spice;
        spice = 0;
    } else {
        spice -= 10;
        harvested = 10;
        chronometer.tick();
    }

    return harvested;
}
