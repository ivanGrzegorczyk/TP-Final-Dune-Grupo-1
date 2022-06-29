#include "server/headers/buildings/HeavyFactory.h"

HeavyFactory::HeavyFactory(int id, coordenada_t coord):
        Building(id, HEAVY_FACTORY_POINTS,
                 BUILDING_HEAVY_FACTORY,
                 coord, HEAVY_FACTORY_ENERGY,
                 HEAVY_FACTORY_COST) {}

std::shared_ptr<Building> HeavyFactory::copy() {
    auto copy = std::make_shared<HeavyFactory>(
            this->getId(), this->getPosition());

    return copy;
}
