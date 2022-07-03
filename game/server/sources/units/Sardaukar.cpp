#include "server/headers/units/Sardaukar.h"

Sardaukar::Sardaukar(int id, coordenada_t coord) : Unit(
        id, SARDAUKAR_HP, SARDAUKAR_RANGE,
        SARDAUKAR_SPEED, UNIT_SARDAUKAR,
        SARDAUKAR_COST, nullptr, coord) {}

std::shared_ptr<Unit> Sardaukar::copy() {
    auto copy = std::make_shared<Sardaukar>(
            this->getId(), this->getPosition());

    return copy;
}
