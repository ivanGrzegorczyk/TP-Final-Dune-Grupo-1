#include <fstream>
#include "yaml-cpp/yaml.h"
#include "server/headers/map/ServerMap.h"
#include "server/headers/map/RockCell.h"
#include "server/headers/map/SandCell.h"

ServerMap::ServerMap(int rows, int columns) : rows(rows), columns(columns),
                                              map(rows, std::vector<ServerCell *>(columns)), entityId(1) {}

std::stack<coordenada_t> ServerMap::A_star(
        coordenada_t start, coordenada_t end) {
    Navigator navigator(map);
    return navigator.A_star(start, end);
}

void ServerMap::spawnUnit(int playerId, int type, coordenada_t position) {
    if (players.find(playerId) == players.end()) {
        players.insert(std::pair<int, Player> (playerId, Player(playerId, 0)));
    }
    if (validPosition(position)) {
        players[playerId].addUnit(entityId, type, position);
        map[position.first][position.second]->occupied = true;
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
                if ((y + i) <= rows && (x + j) <= columns && map[x][y]->ground() == TERRAIN_ROCKS) {
                    aux++;
                }
            }
        }

        if (aux == 6) {
            players[playerId].addBuilding(entityId, buildingType, position);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    map[y + i][x + j]->occupied = true;
                }
            }
            entityId++;
        }
    }
}

void ServerMap::updateUnitsPosition() {
    for (auto & [id, player] : players) {
        player.updateUnitsPosition(map);
    }
}

void ServerMap::addSnapshotData(Snapshot &snapshot) {
    for (auto & [playerId, player] : players) {
        snapshot.addPlayer(playerId);
        player.addUnitData(snapshot);
        player.addBuildingData(snapshot);
        player.addVehicleData(snapshot);
    }
}

void ServerMap::initializeTerrain(std::vector<uint8_t> &terrain) {
    // TODO Colocar el edificio central y crear más terrenos cuando
    // el cliente los pueda renderizas
    std::ifstream file("../game/assets/data.yaml");
    YAML::Node config = YAML::Load(file);
    rows = config["map"]["rows"].as<int>();
    columns = config["map"]["columns"].as<int>();

    map = std::vector<std::vector<ServerCell *>>(
            rows, std::vector<ServerCell *>(columns));
    entityId = 1;

    for(YAML::Node cell : config["map"]["cells"]) {
        auto x = cell["pos"][0].as<int>();
        auto y = cell["pos"][1].as<int>();
        auto _terrain = cell["terrain"].as<std::string>();

        if (_terrain == "rock") {
            map[x][y] = new RockCell({x, y});
            terrain.push_back(TERRAIN_ROCKS);
        } else if (_terrain == "sand") {
            auto spice = cell["seed"].as<unsigned int>();
            map[x][y] = new SandCell({x, y}, spice);
            terrain.push_back(TERRAIN_SAND);
        } else {
            map[x][y] = new SandCell({x, y}, 0);
            terrain.push_back(TERRAIN_SAND);
        }
    }
}

bool ServerMap::validPosition(coordenada_t position) const {
    return position.first >= 0 && position.first < columns
           && position.second >= 0 && position.second < rows;
}

int ServerMap::getRows() const {
    return rows;
}

int ServerMap::getColumns() const {
    return columns;
}

