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
#include "server/headers/units/HeavyInfantry.h"
#include "server/headers/units/Fremen.h"
#include "server/headers/units/Sardaukar.h"

Player::Player(int id, int house) : playerId(id), house(house), money(0) {}

void Player::addUnit(int unitId, int type, coordenada_t position) {
    switch (type) {
        case UNIT_LIGHT_INFANTRY: {
            units.insert(std::pair<int, std::shared_ptr<Unit>> (
                    unitId, new LightInfantry(unitId, position)));
            break;
        }
        case UNIT_HEAVY_INFANTRY: {
            units.insert(std::pair<int, std::shared_ptr<Unit>> (
                    unitId, new HeavyInfantry(unitId, position)));
            break;
        }
        case UNIT_FREMEN: {
            units.insert(std::pair<int, std::shared_ptr<Unit>> (
                    unitId, new Fremen(unitId, position)));
            break;
        }
        case UNIT_SARDAUKAR: {
            units.insert(std::pair<int, std::shared_ptr<Unit>> (
                    unitId, new Sardaukar(unitId, position)));
            break;
        }
        default:
            throw std::runtime_error("Unknown unit");
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

std::shared_ptr<Unit> &Player::getUnit(int unitId) {
    if (units.find(unitId) != units.end())
        return units.at(unitId);
    else
        throw std::runtime_error("Player does not contain unit");
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

std::map<int, std::shared_ptr<Unit>> *Player::getUnits() {
    return &units;
}

int Player::getClosestUnitId(coordenada_t position, unsigned int range) {
    int closest = 0;
    double distance = INFINITY;

    for (auto & [unitId, unit] : units) {
        coordenada_t current = unit->getPosition();
        auto _distance = calculateDistance(position, current);
        if (_distance < distance) {
            distance = _distance;
            if (distance < range)
                closest = unitId;
        }
    }
    if (closest != 0)
        std::cout << "La unidad mas cercana es: " << closest << std::endl;
    return closest;
}

double Player::calculateDistance(coordenada_t unit1, coordenada_t unit2) {
    int x1 = unit1.first, y1 = unit1.second;
    int x2 = unit2.first, y2 = unit2.second;

    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) * 1.0);
}

void Player::kill(int unitId) {
    units.erase(unitId);
}

bool Player::owns(int unitId) {
    if (units.find(unitId) == units.end())
        return false;
    else
        return true;
}

void Player::unitAttackReset() {
    for (auto & [unitId, unit] : units) {
        unit->stopAttacking();
    }
}
