#include "server/headers/buildings/LightFactory.h"

LightFactory::LightFactory(int id, coordenada_t coord):
        Building(id, LIGHT_FACTORY_POINTS,
                 BUILDING_LIGHT_FACTORY,
                 coord, LIGHT_FACTORY_ENERGY,
                 LIGHT_FACTORY_COST) {}

std::shared_ptr<Building> LightFactory::copy() {
    auto copy = std::make_shared<LightFactory>(
            this->getId(), this->getPosition());

    return copy;
}


