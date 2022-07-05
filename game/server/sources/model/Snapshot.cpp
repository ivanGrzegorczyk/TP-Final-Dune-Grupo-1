#include "server/headers/model/Snapshot.h"

const std::map<int, int> & Snapshot::getPlayers() {
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

const std::map<coordenada_t, int> &Snapshot::getTerrainData() {
    return spice_cells;
}

void Snapshot::addPlayer(const int playerId, int money) {
    players[playerId] = money;
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

void Snapshot::addHarvestZone(coordenada_t &position, int spice) {
    if (spice > 0 && spice < 50)
        spice_cells.insert(std::pair<coordenada_t, int> (position, TERRAIN_SPICE_LOW));
    else if (spice > 50)
        spice_cells.insert(std::pair<coordenada_t, int> (position, TERRAIN_SPICE_HIGH));
    else
        spice_cells.insert(std::pair<coordenada_t, int> (position, TERRAIN_SAND));
}
