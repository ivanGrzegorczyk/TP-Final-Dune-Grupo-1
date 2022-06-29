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

unsigned int Refinery::getSpice() const {
    return spice;
}

std::shared_ptr<Building> Refinery::copy() {
    auto copy = std::make_shared<Refinery>(
            this->getId(), this->getSpice(), this->getPosition());

    return copy;
}
