#include "server/headers/units/HeavyInfantry.h"

HeavyInfantry::HeavyInfantry(int id, coordenada_t coord) : Unit(
        id, HEAVY_INFANTRY_HP, HEAVY_INFANTRY_RANGE,
        HEAVY_INFANTRY_SPEED, UNIT_HEAVY_INFANTRY,
        HEAVY_INFANTRY_COST, coord) {}

std::shared_ptr<Unit> HeavyInfantry::copy() {
    auto copy = std::make_shared<HeavyInfantry>(
            this->getId(), this->getPosition());

    return copy;
}
