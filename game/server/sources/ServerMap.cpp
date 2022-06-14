#include "../headers/ServerMap.h"
#include "../../common/headers/Constantes.h"
#include "../../common/headers/LightInfantry.h"

ServerMap::ServerMap(int rows, int columns) :
map(rows, std::vector<ServerCell>(columns)) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j].coords = {i, j};
        }
    }
}

std::stack<coordenada_t> ServerMap::A_star(
        coordenada_t start, coordenada_t end) {
    Navigator navigator(map);
    return navigator.A_star(start, end);
}

bool ServerMap::reposition(int playerId, int unitId, coordenada_t goal, int &updates) {
    try {
        if (units[playerId].at(unitId)->getPosition() == goal)
            return false;
        std::stack<coordenada_t> path = A_star(
                units.at(playerId).at(unitId)->getPosition(), goal);
        updates = path.size();
        units[playerId].at(unitId)->setPath(path);
        return true;  // TODO Revisar caso en el que no hay un camino posible
    } catch(const std::out_of_range &e) {
        return false;
    }
}

void ServerMap::spawnUnit(int playerId, int unit) {
    int unitId = units[playerId].size() + 1; // TODO Que pasa si se elimina alguna unidad? Que id correspondería?
    if (unit == UNIT_LIGHT_INFANTRY)
        units.at(playerId).insert(std::pair<int, Units *> (
                unitId, new LightInfantry(unitId, coordenada_t{playerId, playerId}))); // TODO Las coordenadas estan asi temporalmente
}

void ServerMap::createBuilding(int playerId, int buildingType, const std::vector<coordenada_t>& coords) {
    int buildingId = buildings.at(playerId).size() + 1;

    if (buildingType == BUILDING_BARRACKS) {

    }
}

void ServerMap::addUnitData(std::vector<uint16_t> &vec) {
    for (auto const& [player, unitsMap] : units) {
        uint16_t playerId = player;
        vec.push_back(playerId);
        for (auto const& [unitId, unit] : unitsMap) {
            vec.push_back(uint16_t {10});  // TODO Cuando se agreguen más unidades hay que cambiar esta linea
            vec.push_back((uint16_t) unitId);
            coordenada_t position = unit->getPosition();
            vec.push_back((uint16_t) position.first);
            vec.push_back((uint16_t) position.second);
        }
    }
}

void ServerMap::updateUnitPositions() {
    for (auto const& [player, unitsMap] : units) {
        for (auto const& [unitId, unit] : unitsMap) {
            unit->relocate();
        }
    }
}
