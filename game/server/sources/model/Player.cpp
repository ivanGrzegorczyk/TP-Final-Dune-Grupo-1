#include "server/headers/model/Player.h"
#include "server/headers/units/LightInfantry.h"
#include "server/headers/buildings/Barracks.h"
#include "server/headers/model/Snapshot.h"

Player::Player(int id, int house) : playerId(id), house(house), money(0) {}

void Player::addUnit(int unitId, int type, coordenada_t position) {
    switch (type) {
        case UNIT_LIGHT_INFANTRY: {
            units.insert(std::pair<int, std::shared_ptr<Unit>> (
                    unitId, new LightInfantry(unitId, position)));
            break;
        }
        default:
            return;
    }
}

void Player::addBuilding(
        int buildingId, int buildingType, coordenada_t position) {
    switch (buildingType) {
        case BUILDING_BARRACKS: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new Barracks(buildingId, position)));
            break;
        }
        default:
            return;
    }
}

std::shared_ptr<Unit> Player::getUnit(int unitId) {
    return units.at(unitId);
}

std::shared_ptr<Building> Player::getBuilding(int buildingId) {
    return buildings.at(buildingId);
}

void Player::updateUnitsPosition(std::vector<std::vector<ServerCell *>> &map) {
    for (auto const& [unitId, unit] : units) {
        coordenada_t free = unit->relocate();
        map[unit->getPosition().first][unit->getPosition().second]->occupied = true;
        if (free.first != -1 && free.second != -1)
            map[free.first][free.second]->occupied = false;
    }
}

void Player::addUnitData(Snapshot &snapshot) {
    for (auto const& [unitId, unit] : units) {
        snapshot.addUnit(playerId, unit);
    }
}

void Player::addBuildingData(Snapshot &snapshot) {
    for (auto const& [buildingId, building] : buildings) {
        snapshot.addBuilding(playerId, building);
    }
}
