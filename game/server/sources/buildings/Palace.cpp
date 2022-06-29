#include "server/headers/buildings/Palace.h"

Palace::Palace(int id, coordenada_t coord):
        Building(id, PALACE_POINTS,
                 BUILDING_PALACE,
                 coord, PALACE_ENERGY,
                 PALACE_COST) {}

std::shared_ptr<Building> Palace::copy() {
    auto copy = std::make_shared<Palace>(
            this->getId(), this->getPosition());

    return copy;
}
