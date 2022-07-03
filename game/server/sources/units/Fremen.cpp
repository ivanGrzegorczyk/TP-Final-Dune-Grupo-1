#include "server/headers/units/Fremen.h"

Fremen::Fremen(int id, coordenada_t coord) : Unit(
        id, FREMEN_HP, FREMEN_RANGE,
        FREMEN_SPEED, UNIT_FREMEN,
        FREMEN_COST, nullptr, coord) {}

std::shared_ptr<Unit> Fremen::copy() {
    auto copy = std::make_shared<Fremen>(
            this->getId(), this->getPosition());

    return copy;
}

