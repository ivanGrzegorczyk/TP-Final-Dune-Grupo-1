#ifndef SNAPSHOT_H_
#define SNAPSHOT_H_

#include <map>
#include <vector>
#include <memory>
#include "Unit.h"
#include "common/headers/Vehicle.h"
#include "common/headers/Building.h"

class Snapshot {
private:
    std::vector<int> players;
    std::map<int, std::vector<std::shared_ptr<Unit>>> units;
    std::map<int, std::vector<std::shared_ptr<Building>>> buildings;
    std::map<int, std::vector<std::shared_ptr<Vehicle>>> vehicles;

public:
    std::vector<int> getPlayers();

    std::vector<std::shared_ptr<Unit>> getUnits(int playerId);

    std::vector<std::shared_ptr<Building>> getBuildings(int playerId);

    std::vector<std::shared_ptr<Vehicle>> getVehicles(int playerId);

    void addUnit(int playerId, const std::shared_ptr<Unit>& unit);

    void addPlayer(int playerId);

    void addBuilding(int playerId, const std::shared_ptr<Building> &building);
};

#endif  // SNAPSHOT_H_
