#include "server/headers/model/Snapshot.h"

std::vector<int> Snapshot::getPlayers() {
    return std::move(players);
}

std::vector<std::shared_ptr<Unit>> Snapshot::getUnits(int playerId) {
    return std::move(units[playerId]);
}

std::vector<std::shared_ptr<Building>> Snapshot::getBuildings(int playerId) {
    return std::move(buildings[playerId]);
}

std::vector<std::shared_ptr<Vehicle>> Snapshot::getVehicles(int playerId) {
    return std::move(vehicles[playerId]);
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
