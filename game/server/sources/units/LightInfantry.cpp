#include "../../headers/units/LightInfantry.h"
#include "server/headers/weapons/AssaultRifle.h"

LightInfantry::LightInfantry(int id, coordenada_t coord) : Unit(
        id, LIGHT_INFANTRY_HP, LIGHT_INFANTRY_RANGE,
        LIGHT_INFANTRY_SPEED, UNIT_LIGHT_INFANTRY,
        LIGHT_INFANTRY_COST, new AssaultRifle, coord) {}

std::shared_ptr<Unit> LightInfantry::copy() {
    auto copy = std::make_shared<LightInfantry>(
            this->getId(), this->getPosition());

    return copy;
}
