#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>
#include <map>
#include <vector>
#include "common/headers/Unit.h"
#include "common/headers/Building.h"

class Player {
private:
    int id;
    int house;
    int money;
    std::map<int, std::shared_ptr<Unit>> units;
    std::map<int, std::shared_ptr<Building>> buildings;

public:
    Player() = default;
    Player(int id, int house);

    std::shared_ptr<Unit> getUnit(int unitId);

    void addUnit(int unitId, int type, coordenada_t position);

    void addBuilding(int buildingId, int buildingType, coordenada_t position);

    std::shared_ptr<Building> getBuilding(int buildingId);

    void updateUnitsPosition();

    void addUnitData(std::vector<uint16_t> &snapshot);

    void addBuildingData(std::vector<uint16_t> &snapshot);
};

#endif  // PLAYER_H_