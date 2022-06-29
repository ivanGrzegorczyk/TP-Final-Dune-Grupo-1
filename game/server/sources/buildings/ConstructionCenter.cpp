#include "server/headers/buildings/ConstructionCenter.h"

ConstructionCenter::ConstructionCenter(int id, coordenada_t coord):
        Building(id, CONSTRUCTIONCENTER_POINTS,
                 BUILDING_CONSTRUCTION_CENTER,
                 coord, CONSTRUCTIONCENTER_ENERGY,
                 CONSTRUCTIONCENTER_COST) {}

std::shared_ptr<Building> ConstructionCenter::copy() {
    auto copy = std::make_shared<ConstructionCenter>(
            this->getId(), this->getPosition());

    return copy;
}

