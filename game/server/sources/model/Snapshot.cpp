#include "server/headers/model/Snapshot.h"

std::vector<int> Snapshot::getPlayers() {
    return players;
}

std::vector<Unit *> Snapshot::getUnits(int playerId) {
    return units[playerId];
}

std::vector<Unit *> Snapshot::getBuildings(int playerId) {
    return std::vector<Unit *>();
}

std::vector<Vehicle *> Snapshot::getVehicles(int playerId) {
    return vehicles[playerId];
}

void Snapshot::addUnit(Unit *unit) {

}
