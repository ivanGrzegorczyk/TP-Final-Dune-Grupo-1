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

class Player {
private:
    int playerId;
    int house;
    int money;
    std::map<int, std::shared_ptr<Unit>> units;
    std::map<int, std::shared_ptr<Building>> buildings;
    std::map<int, std::shared_ptr<Vehicle>> vehicles;

public:
    Player() = default;

    Player(int id, int house);

    std::shared_ptr<Unit> & getUnit(int unitId);

    void addUnit(int unitId, int type, coordenada_t position);

    void addBuilding(int buildingId, int buildingType, coordenada_t position);

    std::shared_ptr<Building> getBuilding(int buildingId);

    std::map<int, std::shared_ptr<Unit>> *getUnits();

    void updateUnitsPosition(std::vector<std::vector<ServerCell *>> &map);

    void addUnitData(Snapshot &snapshot);

    void addBuildingData(Snapshot &snapshot);

    void addVehicleData(Snapshot &snapshot);

    int getClosestUnitId(coordenada_t position, unsigned int range);

    double calculateDistance(coordenada_t unit1, coordenada_t unit2);

    void kill(int unitId);

    bool owns(int unitId);
};

#endif  // PLAYER_H_
