#include "server/headers/vehicles/Harvester.h"
#include "server/headers/map/ServerCell.h"

Harvester::Harvester(int id, coordenada_t coord) :
        Vehicle(id, HARVESTER_HP, HARVESTER_RANGE,
                HARVESTER_SPEED, VEHICLE_HARVESTER, HARVESTER_COST, coord), spice(0) {}

Harvester::Harvester(int id, unsigned int spice, coordenada_t coord) :
        Vehicle(id, HARVESTER_HP, HARVESTER_RANGE,
                HARVESTER_SPEED, VEHICLE_HARVESTER, HARVESTER_COST, coord), spice(spice) {}

void Harvester::harvest(ServerCell *cell) {
    try {
        if (spice < MAX_SPICE)
            spice = cell->harvest();
    } catch(const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return;
    }
}

std::shared_ptr<Vehicle> Harvester::copy() {
    auto copy = std::make_shared<Harvester>(
            this->getId(), this->getSpice(), this->getPosition());

    return copy;
}

unsigned int Harvester::getSpice() const {
    return spice;
}
