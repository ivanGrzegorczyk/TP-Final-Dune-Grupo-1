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
