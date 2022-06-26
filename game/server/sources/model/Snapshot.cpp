#include "server/headers/model/Snapshot.h"

std::vector<int> Snapshot::getPlayers() {
    return players;
}

std::vector<std::shared_ptr<Unit>> Snapshot::getUnits(int playerId) {
    return units[playerId];
}

std::vector<std::shared_ptr<Building>> Snapshot::getBuildings(int playerId) {
    return buildings[playerId];
}

std::vector<std::shared_ptr<Vehicle>> Snapshot::getVehicles(int playerId) {
    return vehicles[playerId];
}

void Snapshot::addUnit(Unit *unit) {

}
