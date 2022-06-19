#include <fstream>
#include "../headers/ServerMap.h"
#include "../headers/units/LightInfantry.h"
#include "../headers/buildings/Barracks.h"

ServerMap::ServerMap(int rows, int columns) : rows(rows), columns(columns),
map(rows, std::vector<ServerCell>(columns)), entityId(1) {
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

void ServerMap::reposition(int playerId, int unitId, coordenada_t goal) {
    try {
        if (units[playerId].at(unitId)->getPosition() == goal) {
            std::cout << "Ya esta en esa posicion" << std::endl;
        }

        std::stack<coordenada_t> path = A_star(
                units.at(playerId).at(unitId)->getPosition(), goal);

        units[playerId].at(unitId)->setPath(path);
    } catch(const std::exception &e) {
        std::cout << "No existe la unidad" << std::endl;
    }
}

void ServerMap::spawnUnit(int playerId, int unit, coordenada_t position) {
    // TODO Chequear que las coordenadas estén dentro del mapa
    if (unit == UNIT_LIGHT_INFANTRY) {
        units[playerId].insert(std::pair<int, LightInfantry *>(
                entityId, new LightInfantry(entityId, position)));
        map[position.first][position.second].cellUnits.push_back(units.at(playerId).at(entityId));
        entityId++;
    }
}

void ServerMap::createBuilding(int playerId, int buildingType, coordenada_t position) {
    if (buildingType == BUILDING_BARRACKS) {
        int x = position.first, y = position.second;

        int aux = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if ((y + i) <= rows && (x + j) <= columns && map[x][y].ground == TERRAIN_ROCKS) {
                    aux++;
                }
            }
        }

        if (aux == 6) {
            buildings[playerId].insert(std::pair<int, Barracks *>(
                    entityId, new Barracks(entityId, position)));
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    map[y + i][x + j].building = buildings.at(playerId).at(entityId);
                }
            }
            entityId++;
        }
    }
}

bool ServerMap::updateUnitPositions() {
    bool relocated = false;

    for (auto const& [player, unitsMap] : units) {
        for (auto const& [unitId, unit] : unitsMap) {
            if (unit->relocate() && !relocated)
                relocated = true;
        }
    }
    return relocated;
}

void ServerMap::addUnitData(int playerId, std::vector<uint16_t> &snapshot) {
    snapshot.push_back(units.at(playerId).size());  // Cantidad de unidades para este jugador
    for (auto const& [unitId, unit] : units.at(playerId)) {
        snapshot.push_back((uint16_t) unit->getType());  // Tipo de unidad
        snapshot.push_back((uint16_t) unitId);  // Id de la unidad
        snapshot.push_back((uint16_t) unit->getPosition().first);  // Coordenada x
        snapshot.push_back((uint16_t) unit->getPosition().second);  // Coordenada y
    }
}

void ServerMap::addBuildingData(int playerId, std::vector<uint16_t> &snapshot) {
    snapshot.push_back(buildings.at(playerId).size());  // Cantidad de edificios para este jugador
    for (auto const& [buildingId, building] : buildings.at(playerId)) {
        snapshot.push_back((uint16_t) building->getType());  // Tipo de edificio
        snapshot.push_back((uint16_t) buildingId);  // Id del edificio
        snapshot.push_back((uint16_t) building->getPosition().first);
        snapshot.push_back((uint16_t) building->getPosition().second);
    }
}

void ServerMap::addSnapshotData(std::vector<uint16_t> &snapshot) {
    for (auto const& [player, unitsMap] : units) {
        snapshot.push_back((uint16_t) player);  // PlayerId
        addUnitData(player, snapshot);
        //addBuildingData(player, snapshot);
    }
}

void ServerMap::initializeTerrain() {
    std::ifstream file;
    std::string line;

    file.open("../terrain.txt", std::ifstream::in);
    if (!file.is_open())
        std::cout << "No se abrio el archivo" << std::endl;

    int x = 0;
    while (getline(file, line)) {
        int y = -1;
        for (char c : line) {
            y++;
            if (c == 'O') { // Rocas
                map[x][y].ground = TERRAIN_ROCKS;
            } else if (c == 'X') {           // Arena
                map[x][y].ground = TERRAIN_SAND;
            }
        }
        x++;
    }
    file.close();
}
