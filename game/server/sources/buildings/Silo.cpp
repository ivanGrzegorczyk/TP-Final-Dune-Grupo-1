#include "server/headers/buildings/Silo.h"

Silo::Silo(int id, coordenada_t coord):
        Building(id, SILO_POINTS,
                 BUILDING_SILO,
                 coord, SILO_ENERGY,
                 SILO_COST), capacity(SILO_CAPACITY), spice(0) {}

Silo::Silo(int id, unsigned int spice, coordenada_t coord):
        Building(id, SILO_POINTS,
                 BUILDING_SILO,
                 coord, SILO_ENERGY,
                 SILO_COST), capacity(SILO_CAPACITY), spice(spice) {}

unsigned int Silo::getSpice() const {
    return spice;
}

std::shared_ptr<Building> Silo::copy() {
    auto copy = std::make_shared<Silo>(
            this->getId(), this->getSpice(), this->getPosition());

    return copy;
}
