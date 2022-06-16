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

    units[1].insert(std::pair<int, Units *> (
            1, new LightInfantry(1, coordenada_t{1, 1})));
}

std::stack<coordenada_t> ServerMap::A_star(
        coordenada_t start, coordenada_t end) {
    Navigator navigator(map);
    return navigator.A_star(start, end);
}

bool ServerMap::reposition(int playerId, int unitId, coordenada_t goal, int &updates) {
    std::lock_guard<std::mutex> lock(mutex);
    try {
        if (units[playerId].at(unitId)->getPosition() == goal) {
            std::cout << "Ya esta en esa posicion" << std::endl;
            return false;
        }
        std::cout << "Antes de hacer el algoritmo" << std::endl;
        std::cout << "playerID: " << playerId << std::endl;
        std::cout << "goal_x: " << goal.first << std::endl;
        std::cout << "goal_y: " << goal.second << std::endl;

        std::stack<coordenada_t> path = A_star(
                units.at(playerId).at(unitId)->getPosition(), goal);

        units[playerId].at(unitId)->setPath(path);
        return true;  // TODO Revisar caso en el que no hay un camino posible
    } catch(const std::exception &e) {
        std::cout << "No existe la unidad" << std::endl;
        return false;
    }
}

void ServerMap::spawnUnit(int playerId, int unit) {
    std::lock_guard<std::mutex> lock(mutex);
    int unitId = units[playerId].size() + 1; // TODO Que pasa si se elimina alguna unidad? Que id correspondería?
    if (unit == UNIT_LIGHT_INFANTRY)
        units.at(playerId).insert(std::pair<int, Units *> (
                unitId, new LightInfantry(unitId, coordenada_t{playerId, playerId}))); // TODO Las coordenadas estan asi temporalmente
}

void ServerMap::createBuilding(int playerId, int buildingType, const std::vector<coordenada_t>& coords) {
    std::lock_guard<std::mutex> lock(mutex);
    int buildingId = buildings.at(playerId).size() + 1;

    if (buildingType == BUILDING_BARRACKS) {

    }
}

void ServerMap::addUnitData(std::vector<uint16_t> &vec) {
    std::lock_guard<std::mutex> lock(mutex);
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

bool ServerMap::updateUnitPositions() {
    std::lock_guard<std::mutex> lock(mutex);
    bool relocated = false;

    for (auto const& [player, unitsMap] : units) {
        for (auto const& [unitId, unit] : unitsMap) {
            if (unit->relocate() && !relocated)
                relocated = true;
        }
    }
    return relocated;
}
