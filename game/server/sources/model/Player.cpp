#include "server/headers/model/Player.h"
#include "server/headers/units/LightInfantry.h"
#include "server/headers/buildings/Barracks.h"

Player::Player(int id, int house) : id(id), house(house), money(0) {}

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

void Player::updateUnitsPosition() {
    for (auto const& [unitId, unit] : units) {
        unit->relocate();
    }
}

void Player::addUnitData(std::vector<uint16_t> &snapshot) {
    snapshot.push_back(units.size());  // Cantidad de unidades para este jugador
    for (auto const& [unitId, unit] : units) {
        uint16_t eventType = UNIT;
        snapshot.push_back(eventType);
        snapshot.push_back((uint16_t) unit->getType());  // Tipo de unidad
        snapshot.push_back((uint16_t) unitId);  // Id de la unidad
        snapshot.push_back(
                (uint16_t) unit->getPosition().first);  // Coordenada x
        snapshot.push_back(
                (uint16_t) unit->getPosition().second);  // Coordenada y
    }
}

void Player::addBuildingData(std::vector<uint16_t> &snapshot) {
    snapshot.push_back(buildings.size());  // Cantidad de edificios para este jugador
    snapshot.push_back(BUILDING);
    for (auto const& [buildingId, building] : buildings) {
        snapshot.push_back((uint16_t) building->getType());  // Tipo de unidad
        snapshot.push_back((uint16_t) buildingId);  // Id de la unidad
        snapshot.push_back(
                (uint16_t) building->getPosition().first);  // Coordenada x
        snapshot.push_back(
                (uint16_t) building->getPosition().second);  // Coordenada y
    }
}
