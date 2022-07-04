#include "server/headers/vehicles/Harvester.h"
#include "server/headers/map/ServerCell.h"
#include "server/headers/buildings/Refinery.h"

Harvester::Harvester(int id, coordenada_t coord) :
        Vehicle(id, HARVESTER_HP, HARVESTER_RANGE,
                HARVESTER_SPEED, VEHICLE_HARVESTER,
                HARVESTER_COST, coord), spice(0), 
                unloading(false), refinery(0),
                working_position(-1, -1){}

Harvester::Harvester(int id, int spice, coordenada_t coord) :
        Vehicle(id, HARVESTER_HP, HARVESTER_RANGE,
                HARVESTER_SPEED, VEHICLE_HARVESTER,
                HARVESTER_COST, coord), spice(spice), 
                unloading(false), refinery(0),
                working_position(-1, -1) {}

void Harvester::harvest(ServerCell *cell) {
    try {
        if (spice < MAX_SPICE) {
            spice = cell->harvest();
        }
    } catch(const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return;
    }
}

void Harvester::setUnloading(bool _unloading) {
    this->unloading = _unloading;
}

void Harvester::setRefinery(int _refinery) {
    this->refinery = _refinery;
}

std::shared_ptr<Vehicle> Harvester::copy() {
    auto copy = std::make_shared<Harvester>(
            this->getId(), this->getSpice(), this->getPosition());

    return copy;
}

int Harvester::getSpice() const {
    return spice;
}

bool Harvester::isFull() const {
    return spice == MAX_SPICE;
}

bool Harvester::isEmpty() const {
    return spice == 0;
}

bool Harvester::isUnloading() const {
    return unloading;
}

coordenada_t Harvester::getWorkingPosition() const {
    return working_position;
}

void Harvester::setWorkingPosition(coordenada_t position) {
    working_position = position;
}

int Harvester::getRefinery() const {
    return refinery;
}

coordenada_t Harvester::relocate() {
    if (path.empty()) {

        return {-1, -1};
    }

    coordenada_t free = coord;
    coord = path.top();
    path.pop();
    return free;
}

unsigned int Harvester::unload(std::shared_ptr<Refinery> &goal) {
    unsigned int ret = 0;
    if (isEmpty()) {
        unloading = false;
        return ret;
    }
    if (chronometer.tack() >= UNLOAD_TIME) {
        ret = goal->load(spice);
        chronometer.tick();
    }

    return ret;
}
