#include "server/headers/buildings/Refinery.h"

Refinery::Refinery(int id, coordenada_t coord):
        Building(id, REFINERY_POINTS,
                 BUILDING_REFINERY,
                 coord, REFINERY_ENERGY,
                 REFINERY_COST), capacity(REFINERY_CAPACITY), spice(0) {}

Refinery::Refinery(int id, unsigned int spice, coordenada_t coord):
        Building(id, REFINERY_POINTS,
        BUILDING_REFINERY,
        coord, REFINERY_ENERGY,
        REFINERY_COST), capacity(REFINERY_CAPACITY), spice(spice) {}

int Refinery::getSpice() const {
    return spice;
}

std::shared_ptr<Building> Refinery::copy() {
    auto copy = std::make_shared<Refinery>(
            this->getId(), this->getSpice(), this->getPosition());

    return copy;
}

bool Refinery::isFull() const {
    return capacity == spice;
}

unsigned int Refinery::load(int &harvesterSpice) {
    unsigned int ret;
    int unloaded;
    if (harvesterSpice - MAX_UNLOADED < 0) {
        unloaded = harvesterSpice;
        harvesterSpice = 0;
    } else {
        harvesterSpice -= MAX_UNLOADED;
        unloaded = MAX_UNLOADED;
    }

    if (spice + unloaded >= capacity) {
        ret = capacity - spice;
        spice = capacity;
    } else {
        spice += unloaded;
        ret = unloaded;
    }

    return ret;
}

int Refinery::getCapacity() const {
    return capacity;
}
