#include <fstream>
#include "../headers/ServerMap.h"

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

void ServerMap::spawnUnit(int playerId, int type, coordenada_t position) {
    if (validPosition(position)) {
        players[playerId].addUnit(entityId, type, position);
        map[position.first][position.second].cellUnits.push_back(
                players.at(playerId).getUnit(entityId));
        entityId++;
    }
}

void ServerMap::reposition(int playerId, int unitId, coordenada_t goal) {
    try {
        if (players.at(playerId).getUnit(unitId)->getPosition() == goal) {
            std::cout << "Ya esta en esa posicion" << std::endl;
            return;
        }

        std::stack<coordenada_t> path = A_star(
                players.at(playerId).getUnit(unitId)->getPosition(), goal);

        players.at(playerId).getUnit(unitId)->setPath(path);
    } catch(const std::exception &e) {
        std::cout << "No existe la unidad" << std::endl;
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
            players[playerId].addBuilding(entityId, buildingType, position);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    map[y + i][x + j].building = players.at(playerId).getBuilding(entityId);
                }
            }
            entityId++;
        }
    }
}

void ServerMap::updateUnitsPosition() {
    for (auto & [id, player] : players) {
       player.updateUnitsPosition();
    }
}

void ServerMap::addSnapshotData(std::vector<uint16_t> &snapshot) {
    for (auto & [playerId, player] : players) {
        snapshot.push_back((uint16_t) playerId);
        player.addUnitData(snapshot);
        //player.addBuildingData(snapshot);
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

bool ServerMap::validPosition(coordenada_t position) const {
    return position.first >= 0 && position.first < columns
    && position.second >= 0 && position.second < rows;
}
