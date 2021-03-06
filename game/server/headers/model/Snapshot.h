#ifndef SNAPSHOT_H_
#define SNAPSHOT_H_

#include <map>
#include <vector>
#include <memory>
#include "server/headers/units/Unit.h"
#include "server/headers/vehicles/Vehicle.h"
#include "server/headers/buildings/Building.h"

class Snapshot {
private:
    std::map<int, int> players;
    std::map<int, std::vector<std::shared_ptr<Unit>>> units;
    std::map<int, std::vector<std::shared_ptr<Building>>> buildings;
    std::map<int, std::vector<std::shared_ptr<Vehicle>>> vehicles;
    std::map<int, std::vector<std::shared_ptr<Unit>>> dead_units;
    std::map<coordenada_t, int> spice_cells;

public:
    const std::map<int, int> & getPlayers();

    const std::vector<std::shared_ptr<Unit>> & getUnits(int playerId);

    const std::vector<std::shared_ptr<Building>> & getBuildings(int playerId);

    const std::vector<std::shared_ptr<Vehicle>> & getVehicles(int playerId);

    const std::vector<std::shared_ptr<Unit>> & getDeadUnits(int playerId);

    void addPlayer(int playerId, int money);

    void addUnit(int playerId, const std::shared_ptr<Unit> &unit);

    void addBuilding(int playerId, const std::shared_ptr<Building> &building);

    void addVehicle(int playerId, const std::shared_ptr<Vehicle> &vehicle);

    void addDeadUnit(int playerId, const std::shared_ptr<Unit> &dead_unit);

    void addHarvestZone(coordenada_t &position, int spice);

    const std::map<coordenada_t, int> & getTerrainData();
};

#endif  // SNAPSHOT_H_
