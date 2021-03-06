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
#include "server/headers/buildings/ConstructionCenter.h"

Player::Player(int id, int house) : playerId(id), house(house), money(1000) {}

bool Player::addUnit(int unitId, int type, coordenada_t position) {
    switch (type) {
        case UNIT_LIGHT_INFANTRY: {
            if (money >= LIGHT_INFANTRY_COST) {
                units.insert(std::pair<int, std::shared_ptr<Unit>> (
                        unitId, new LightInfantry(unitId, position)));
                money -= LIGHT_INFANTRY_COST;
                return true;
            }
            break;
        }
        case UNIT_HEAVY_INFANTRY: {
            if (money >= HEAVY_INFANTRY_COST) {
                units.insert(std::pair<int, std::shared_ptr<Unit>>(
                        unitId, new HeavyInfantry(unitId, position)));
                money -= HEAVY_INFANTRY_COST;
                return true;
            }
            break;
        }
        case UNIT_FREMEN: {
            if (money >= FREMEN_COST) {
                units.insert(std::pair<int, std::shared_ptr<Unit>>(
                        unitId, new Fremen(unitId, position)));
                money -= FREMEN_COST;
                return true;
            }
            break;
        }
        case UNIT_SARDAUKAR: {
            if (money >= SARDAUKAR_COST) {
                units.insert(std::pair<int, std::shared_ptr<Unit>>(
                        unitId, new Sardaukar(unitId, position)));
                money -= SARDAUKAR_COST;
                return true;
            }
            break;
        }
        default:
            throw std::runtime_error("Unknown unit");
    }
    return false;
}

bool Player::addVehicle(int vehicleId, int type, coordenada_t position) {
    switch (type) {
        case VEHICLE_HARVESTER: {
            if (money >= HARVESTER_COST) {
                harvesters.insert(std::pair<int, std::shared_ptr<Harvester>>(
                        vehicleId, new Harvester(vehicleId, position)));
                money -= VEHICLE_HARVESTER;
                return true;
            }
            break;
        }
        default:
            throw std::runtime_error("Unknown vehicle");
    }
    return false;
}

bool Player::addBuilding(
        int buildingId, int buildingType, coordenada_t position) {
    switch (buildingType) {
        case BUILDING_CONSTRUCTION_CENTER: {
            buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                    buildingId, new ConstructionCenter(buildingId, position)));
            return true;
        }
        case BUILDING_LIGHT_FACTORY: {
            if (money >= LIGHT_FACTORY_COST) {
                buildings.insert(std::pair<int, std::shared_ptr<Building>>(
                        buildingId, new LightFactory(buildingId, position)));
                money -= LIGHT_FACTORY_COST;
                return true;
            }
            break;
        }
        case BUILDING_AIR_TRAP: {
            if (money >= AIR_TRAP_COST) {
                buildings.insert(std::pair<int, std::shared_ptr<Building>>(
                        buildingId, new AirTrap(buildingId, position)));
                money -= AIR_TRAP_COST;
                return true;
            }
            break;
        }
        case BUILDING_HEAVY_FACTORY: {
            if (money >= HEAVY_FACTORY_COST) {
                buildings.insert(std::pair<int, std::shared_ptr<Building>>(
                        buildingId, new HeavyFactory(buildingId, position)));
                money -= HEAVY_FACTORY_COST;
                return true;
            }
            break;
        }
        case BUILDING_REFINERY: {
            if (money >= REFINERY_COST) {
                refineries.insert(std::pair<int, std::shared_ptr<Refinery>>(
                        buildingId, new Refinery(buildingId, position)));
                money -= REFINERY_COST;
                return true;
            }
            break;
        }
        case BUILDING_SILO: {
            if (money >= SILO_COST) {
                buildings.insert(std::pair<int, std::shared_ptr<Building>>(
                        buildingId, new Silo(buildingId, position)));
                money -= SILO_COST;
                return true;
            }
            break;
        }
        case BUILDING_BARRACKS: {
            if (money >= BARRACKS_COST) {
                buildings.insert(std::pair<int, std::shared_ptr<Building>>(
                        buildingId, new Barracks(buildingId, position)));
                money -= BARRACKS_COST;
                return true;
            }
            break;
        }
        case BUILDING_PALACE: {
            if (money >= PALACE_COST) {
                buildings.insert(std::pair<int, std::shared_ptr<Building>> (
                        buildingId, new Palace(buildingId, position)));
                money -= PALACE_COST;
                return true;
            }
            break;
        }
        default:
            throw std::runtime_error("Unkonwn building");
    }
    return false;
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
    for (auto const& [buildingId, building] : refineries) {
        auto _building = building->copy();
        snapshot.addBuilding(playerId, _building);
    }
}

void Player::addVehicleData(Snapshot &snapshot) {
    for (auto const& [vehicleId, vehicle] : harvesters) {
        auto _vehicle = vehicle->copy();
        snapshot.addVehicle(playerId, _vehicle);
    }
}

void Player::addDeadUnitData(Snapshot &snapshot) {
    for (auto const& [unitId, dead_unit] : dead_units) {
        auto unit = dead_unit->copy();
        snapshot.addDeadUnit(playerId, unit);
    }
    dead_units.clear();
}

std::map<int, std::shared_ptr<Unit>> *Player::getUnits() {
    return &units;
}

std::map<int, std::shared_ptr<Harvester>>* Player::getHarvesters() {
    return &harvesters;
}

std::map<int, std::shared_ptr<Refinery>>* Player::getRefineries() {
    return &refineries;
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
    if (units.find(unitId) != units.end()) {
        dead_units[unitId] = std::move(units[unitId]);
        units.erase(unitId);
    }
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

int Player::getEntityType(int entityId) {
    if (units.find(entityId) != units.end())
        return UNIT;
    else if (vehicles.find(entityId) != vehicles.end())
        return VEHICLE;
    else if (harvesters.find(entityId) != harvesters.end())
        return VEHICLE_HARVESTER;
    else
        return 0;
}

std::shared_ptr<Harvester> Player::getHarvester(int harvesterId) {
    return harvesters.at(harvesterId);
}

int Player::getClosestRefineryId(const coordenada_t &position) {
    int closest = 0;
    double distance = INFINITY;

    for (auto & [refineryId, refinery] : refineries) {
        std::cout << "Hay una refineria" << std::endl;
        coordenada_t current = refinery->getPosition();
        auto _distance = calculateDistance(position, current);
        if (_distance < distance && !refinery->isFull()) {
            distance = _distance;
            closest = refineryId;
        }
    }

    return closest;
}

std::shared_ptr<Refinery> Player::getRefinery(int refineryId) {
    return refineries.at(refineryId);
}

void Player::addMoney(int _money) {
    money += _money;
}

int Player::getMoney() const {
    return money;
}

bool Player::checkForBuilding(coordenada_t &position) {
    for (const auto & [buildingId, building] : buildings) {
        if (building->getPosition() == position)
            return true;
    }
    for (const auto & [buildingId, building] : refineries) {
        if (building->getPosition() == position)
            return true;
    }
    return false;
}
