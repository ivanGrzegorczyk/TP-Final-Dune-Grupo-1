#include "../../headers/buildings/Barracks.h"

Barracks::Barracks(int id, coordenada_t coord) :
Building(id, BARRACKS_POINTS, BUILDING_BARRACKS,
         coord, BARRACKS_ENERGY, BARRACKS_COST) {}

std::shared_ptr<Building> Barracks::copy() {
    auto copy = std::make_shared<Barracks>(this->getId(), this->getPosition());

    return copy;
}
