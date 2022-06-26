#ifndef SNAPSHOT_H_
#define SNAPSHOT_H_

#include <map>
#include <vector>
#include "Unit.h"
#include "common/headers/Vehicle.h"

class Snapshot {
private:
    std::vector<int> players;
    std::map<int, std::vector<Unit *>> units;
    std::map<int, std::vector<Vehicle *>> vehicles;

public:
    std::vector<int> getPlayers();

    std::vector<Unit *> getUnits(int playerId);

    void addUnit(Unit *unit);

    std::vector<Vehicle *> getVehicles(int playerId);

    std::vector<Unit *> getBuildings(int playerId);
};

#endif  // SNAPSHOT_H_
