#include "server/headers/model/Snapshot.h"

const std::vector<int> & Snapshot::getPlayers() {
    return players;
}

const std::vector<std::shared_ptr<Unit>> &Snapshot::getUnits(int playerId) {
    return units[playerId];
}

const std::vector<std::shared_ptr<Building>> &Snapshot::getBuildings(int playerId) {
    return buildings[playerId];
}

const std::vector<std::shared_ptr<Vehicle>> &Snapshot::getVehicles(int playerId) {
    return vehicles[playerId];
}

const std::vector<std::shared_ptr<Unit>> &Snapshot::getDeadUnits(int playerId) {
    return dead_units[playerId];
}

void Snapshot::addPlayer(const int playerId) {
    players.push_back(playerId);
}

void Snapshot::addUnit(int playerId, const std::shared_ptr<Unit> &unit) {
    units[playerId].push_back(unit);
}

void Snapshot::addBuilding(int playerId, const std::shared_ptr<Building> &building) {
    buildings[playerId].push_back(building);
}

void Snapshot::addVehicle(int playerId, const std::shared_ptr<Vehicle> &vehicle) {
    vehicles[playerId].push_back(vehicle);
}

void Snapshot::addDeadUnit(int playerId, const std::shared_ptr<Unit> &dead_unit) {
    dead_units[playerId].push_back(dead_unit);
}
