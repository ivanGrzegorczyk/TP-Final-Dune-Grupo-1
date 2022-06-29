#include "server/headers/buildings/ConstructionCenter.h"

ConstructionCenter::ConstructionCenter(int id, coordenada_t coord):
        Building(id, CONSTRUCTION_CENTER_POINTS,
                 BUILDING_CONSTRUCTION_CENTER,
                 coord, CONSTRUCTION_CENTER_ENERGY,
                 CONSTRUCTION_CENTER_COST) {}

std::shared_ptr<Building> ConstructionCenter::copy() {
    auto copy = std::make_shared<ConstructionCenter>(
            this->getId(), this->getPosition());

    return copy;
}

