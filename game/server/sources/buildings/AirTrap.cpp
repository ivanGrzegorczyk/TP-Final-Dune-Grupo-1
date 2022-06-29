#include "server/headers/buildings/AirTrap.h"

AirTrap::AirTrap(int id, coordenada_t coord):
        Building(id, AIR_TRAP_POINTS,
                 BUILDING_AIR_TRAP,
                 coord, AIR_TRAP_ENERGY,
                 AIR_TRAP_COST) {}

std::shared_ptr<Building> AirTrap::copy() {
    auto copy = std::make_shared<AirTrap>(
            this->getId(), this->getPosition());

    return copy;
}

