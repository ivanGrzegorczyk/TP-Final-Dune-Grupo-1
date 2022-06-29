#include "server/headers/model/Player.h"
#include "server/headers/units/LightInfantry.h"
#include "server/headers/buildings/Barracks.h"
#include "server/headers/model/Snapshot.h"
#include "server/headers/buildings/LightFactory.h"
#include "server/headers/buildings/AirTrap.h"
#include "server/headers/buildings/HeavyFactory.h"
#include "server/headers/buildings/Refinery.h"
#include "server/headers/buildings/Silo.h"
#include "server/headers/buildings/Palace.h"

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
        case BUILDING_LIGHT_FACTORY: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new LightFactory(buildingId, position)));
            break;
        }
        case BUILDING_AIR_TRAP: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new AirTrap(buildingId, position)));
            break;
        }
        case BUILDING_HEAVY_FACTORY: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new HeavyFactory(buildingId, position)));
            break;
        }
        case BUILDING_REFINERY: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new Refinery(buildingId, position)));
            break;
        }
        case BUILDING_SILO: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new Silo(buildingId, position)));
            break;
        }
        case BUILDING_BARRACKS: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new Barracks(buildingId, position)));
            break;
        }
        case BUILDING_PALACE: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new Palace(buildingId, position)));
            break;
        }
        default:
            throw std::runtime_error("Unkonwn building");
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
        auto _unit = unit->copy();
        snapshot.addUnit(playerId, _unit);
    }
}

void Player::addBuildingData(Snapshot &snapshot) {
    for (auto const& [buildingId, building] : buildings) {
        auto _building = building->copy();
        snapshot.addBuilding(playerId, _building);
    }
}

void Player::addVehicleData(Snapshot &snapshot) {
    for (auto const& [vehicleId, vehicle] : vehicles) {
        auto _vehicle = vehicle->copy();
        snapshot.addVehicle(playerId, _vehicle);
    }
}
