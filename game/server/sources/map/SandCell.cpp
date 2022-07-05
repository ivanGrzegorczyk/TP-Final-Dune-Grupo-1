#include "server/headers/map/SandCell.h"

#define HARVEST_TIME 1000000  // Tiempo que tarda en cosechar MAX_HARVESTED
#define MAX_HARVESTED 10

SandCell::SandCell(coordenada_t coord, unsigned int spice) : ServerCell(coord), spice(spice) {}

int SandCell::ground() {
    return TERRAIN_SAND;
}

unsigned int SandCell::harvest() {
    unsigned int harvested = 0;

    if (chronometer.tack() >= HARVEST_TIME) {
        if (spice < MAX_HARVESTED) {
            harvested = spice;
            spice = 0;
        } else {
            spice -= MAX_HARVESTED;
            harvested = MAX_HARVESTED;
            chronometer.tick();
        }
    }

    return harvested;
}

bool SandCell::harvestable() {
    return spice > 0;
}

int SandCell::getSpice() {
    return spice;
}
