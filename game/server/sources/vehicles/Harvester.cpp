#include "server/headers/vehicles/Harvester.h"
#include "server/headers/map/ServerCell.h"

Harvester::Harvester(int id, coordenada_t coord) :
        Vehicle(id, HARVESTER_HP, HARVESTER_RANGE,
                HARVESTER_SPEED, VEHICLE_HARVESTER, HARVESTER_COST, coord), spice(0) {}

void Harvester::harvest(ServerCell *cell) {
    try {
        if (spice < 200)
            spice = cell->harvest();
    } catch(const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return;
    }
}
