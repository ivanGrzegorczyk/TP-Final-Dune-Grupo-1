#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>
#include <map>
#include <vector>
#include "server/headers/units/Unit.h"
#include "server/headers/buildings/Building.h"
#include "server/headers/vehicles/Vehicle.h"
#include "server/headers/map/ServerCell.h"
#include "Snapshot.h"
#include "server/headers/vehicles/Harvester.h"
#include "server/headers/buildings/Refinery.h"

class Player {
private:
    int playerId;
    int house;
    int money;
    std::map<int, std::shared_ptr<Unit>> units;
    std::map<int, std::shared_ptr<Unit>> dead_units;
    std::map<int, std::shared_ptr<Building>> buildings;
    std::map<int, std::shared_ptr<Vehicle>> vehicles;

    std::map<int, std::shared_ptr<Refinery>> refineries;
    std::map<int, std::shared_ptr<Harvester>> harvesters;

public:
    Player() = default;

    Player(int id, int house);

    std::shared_ptr<Unit> & getUnit(int unitId);

    void addUnit(int unitId, int type, coordenada_t position);

    void addBuilding(int buildingId, int buildingType, coordenada_t position);

    std::shared_ptr<Building> getBuilding(int buildingId);

    std::map<int, std::shared_ptr<Unit>>* getUnits();

    std::map<int, std::shared_ptr<Harvester>>* getHarvesters();

    void addUnitData(Snapshot &snapshot);

    void addBuildingData(Snapshot &snapshot);

    void addVehicleData(Snapshot &snapshot);

    void addDeadUnitData(Snapshot &snapshot);

    int getClosestUnitId(coordenada_t position, unsigned int range);

    double calculateDistance(coordenada_t unit1, coordenada_t unit2);

    void kill(int unitId);

    bool owns(int unitId);

    void unitAttackReset();
    std::map<int, std::shared_ptr<Refinery>> *getRefineries();

    int getEntityType(int entityId);

    std::shared_ptr<Harvester> getHarvester(int harvesterId);

    int getClosestRefineryId(const coordenada_t &position);

    std::shared_ptr<Refinery> getRefinery(int refineryId);

    void addVehicle(int vehicleId, int type, coordenada_t position);

    void addMoney(unsigned int money);

    int getMoney() const;
};

#endif  // PLAYER_H_
