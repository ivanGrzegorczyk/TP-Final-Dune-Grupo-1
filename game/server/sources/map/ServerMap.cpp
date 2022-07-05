#include <fstream>
#include "yaml-cpp/yaml.h"
#include "server/headers/map/ServerMap.h"
#include "server/headers/map/RockCell.h"
#include "server/headers/map/SandCell.h"
#include "server/headers/map/DunesCell.h"
#include "server/headers/map/CliffsCell.h"
#include "server/headers/map/TopsCell.h"

#define YAML_SAND "sand"
#define YAML_DUNE "dune"
#define YAML_ROCK "rock"
#define YAML_TOP "mountain"
#define YAML_CLIFF "cliff"

ServerMap::ServerMap(int rows, int columns) : rows(rows), columns(columns),
                                              map(rows, std::vector<ServerCell *>(columns)), entityId(1) {}

std::stack<coordenada_t> ServerMap::A_star(
        coordenada_t start, coordenada_t end) {
    Navigator navigator(map);
    return navigator.A_star(start, end);
}

void ServerMap::spawnUnit(int playerId, int type, int buildingId) {
    if (players.find(playerId) == players.end()) {
        players.insert(std::pair<int, Player> (playerId, Player(playerId, 0)));
    }
    if (players[playerId].getEntityType(buildingId) != BUILDING)
        return;
    coordenada_t position = players[playerId].getBuilding(buildingId)->getPosition();
    position.second -= 1;
    if (players[playerId].addUnit(entityId, type, position)) {
        map[position.first][position.second]->occupied = true;
        entityId++;
    }
}

void ServerMap::spawnVehicle(int playerId, int type, coordenada_t position) {
    if (!validPosition(position))
        return;

    players[playerId].addVehicle(entityId, type, position);
    map[position.first][position.second]->occupied = true;
    entityId++;
}

void ServerMap::reposition(int playerId, int id, coordenada_t goal, bool userMoved) {
    try {
        auto entityType = players.at(playerId).getEntityType(id);

        coordenada_t original;

        switch (entityType) {
            case UNIT: {
                if (userMoved)
                    players.at(playerId).getUnit(id)->setTarget(0, 0);
                original = players.at(playerId).getUnit(id)->getPosition();
                std::stack<coordenada_t> path = A_star(original, goal);
                players.at(playerId).getUnit(id)->setPath(path);
                players.at(playerId).getUnit(id)->relocate();
                break;
            }
//            case VEHICLE: {
////                original = players.at(playerId).getVehicle(entityId)->getPosition();
//                break;
//            }
            case VEHICLE:
            case VEHICLE_HARVESTER: {
                original = players.at(playerId).getHarvester(id)->getPosition();
                std::stack<coordenada_t> path = A_star(original, goal);
                if (userMoved)
                    players.at(playerId).getHarvester(id)->setWorkingPosition(goal);
                players.at(playerId).getHarvester(id)->setPath(path);
                players.at(playerId).getHarvester(id)->relocate();
                break;
            }
            default:
                throw std::exception();
        }
    } catch(const std::exception &e) {
        std::cout << "Error al reposicionar" << std::endl;
    }
}

void ServerMap::createBuilding(int playerId, int buildingType, coordenada_t position) {
    if (players.find(playerId) == players.end()) {
        players.insert(std::pair<int, Player> (playerId, Player(playerId, 0)));
    }
    if (!validPosition(position))
        return;

    switch (buildingType) {
        case BUILDING_LIGHT_FACTORY: {
            build(playerId, position, BUILDING_LIGHT_FACTORY, 3, 3);
            break;
        }
        case BUILDING_AIR_TRAP: {
            build(playerId, position, BUILDING_AIR_TRAP, 3, 3);
            break;
        }
        case BUILDING_HEAVY_FACTORY: {
            build(playerId, position, BUILDING_HEAVY_FACTORY, 4, 4);
            break;
        }
        case BUILDING_REFINERY: {
            build(playerId, position, BUILDING_REFINERY, 3, 3);
            break;
        }
        case BUILDING_SILO: {
            build(playerId, position, BUILDING_SILO, 1, 1);
            break;
        }
        case BUILDING_BARRACKS: {
            build(playerId, position, BUILDING_BARRACKS, 2, 3);
            break;
        }
        case BUILDING_PALACE: {
            build(playerId, position, BUILDING_PALACE, 3, 3);
            break;
        }
        default:
            throw std::runtime_error("Unkonwn building");
    }
}

void ServerMap::updateUnitsPosition() {
    for (auto & [id, player] : players) {
        auto units = player.getUnits();
        for (auto const& [unitId, unit] : *units) {
            coordenada_t next = unit->getNextPosition();
            if(next.first >= 0 && next.second >= 0)
                if(map[next.first][next.second]->occupied) {
                    reposition(id, unitId, unit->getGoal(), true);
                }
            coordenada_t free = unit->relocate();
            map[unit->getPosition().first][unit->getPosition().second]->occupied = true;
            if (validPosition(free)) {
                map[free.first][free.second]->occupied = false;
            }
        }
    }
}

void ServerMap::updateHarvestersStatus() {
    for (auto & [playerId, player] : players) {
        auto harvesters = player.getHarvesters();
        for (auto &[harvesterId, harvester]: *harvesters) {
            if (harvester->isStill()) {
                if (!harvester->isFull() && !harvester->isUnloading()) {
                    coordenada_t position = harvester->getWorkingPosition();
                    if (validPosition(position)) {
                        if (harvester->getPosition() == position) {
                            if (map[position.first][position.second]->harvestable()) {
                                harvester->harvest(map[position.first][position.second]);
                            } else {
                                coordenada_t newPosition = findClosestHarvestableCell(harvester->getPosition());
                                harvester->setWorkingPosition(newPosition);
                            }
                        } else {
                            reposition(playerId, harvesterId, position, false);
                            harvester->relocate();
                        }
                    }
                } else if (harvester->isFull() && !harvester->isUnloading()) {
                    harvester->setUnloading(true);
                    coordenada_t current = harvester->getPosition();
                    int closestId = player.getClosestRefineryId(current);
                    if (closestId != 0) {
                        harvester->setRefinery(closestId);
                        reposition(playerId, harvesterId,
                                   player.getRefinery(harvester->getRefinery())->getPosition(), false);
                        harvester->relocate();
                    }
                } else if (!harvester->isEmpty() && harvester->isUnloading()) {
                    auto refinery = player.getRefinery(harvester->getRefinery());
                    unsigned int money = harvester->unload(refinery);
                    player.addMoney(money);
                }
            } else {
                coordenada_t next = harvester->getNextPosition();
                if(next.first >= 0 && next.second >= 0)
                    if(map[next.first][next.second]->occupied) {
                        reposition(playerId, harvesterId, harvester->getGoal(), false);
                    }
                coordenada_t free = harvester->relocate();
                map[harvester->getPosition().first][harvester->getPosition().second]->occupied = true;
                if (validPosition(free)) {
                    map[free.first][free.second]->occupied = false;
                }
            }
        }
    }
}

void ServerMap::unitCheck() {
    for (auto & [playerId1, player1] : players) {
        auto units = player1.getUnits();
        for (auto & [unitId, unit] : *units) {
            if (unit->isStill() && !unit->hasTarget()) {
                for (auto &[playerId2, player2]: players) {
                    if (playerId1 != playerId2) {
                        int target = player2.getClosestUnitId(unit->getPosition(), unit->getRange());
                        unit->setTarget(playerId2, target);
                    }
                }
            }
        }
    }
    for (auto & [playerId, player] : players) {
        auto units = player.getUnits();
        for (auto & [unitId, unit] : *units) {
            if (unit->hasTarget()) {
                coordenada_t coord;
                try {
                     coord = players[unit->getTarget().first].getUnit(unit->getTarget().second)->getPosition();
                } catch (const std::runtime_error &e) {
                    unit->setTarget(0, 0);
                    unit->stopMoving();
                    continue;
                }
                if (player.calculateDistance(unit->getPosition(), coord) > (double) unit->getRange()) {
                    reposition(playerId, unitId, coord, false);
                    unit->relocate();
                } else {
                    unit->stopMoving();
                    bool killed = unit->attack(players[unit->getTarget().first].getUnit(unit->getTarget().second));
                    if (killed) {
                        players[unit->getTarget().first].kill(unit->getTarget().second);
                        unit->setTarget(0, 0);
                        unit->stopMoving();
                    }
                }
            }
        }
    }
}

void ServerMap::addSnapshotData(Snapshot &snapshot) {
    for (auto & [playerId, player] : players) {
        snapshot.addPlayer(playerId, player.getMoney());
        player.addUnitData(snapshot);
        player.addBuildingData(snapshot);
        player.addVehicleData(snapshot);
        player.addDeadUnitData(snapshot);
    }
    addTerrainData(snapshot);
}

void ServerMap::initializeTerrain(std::vector<uint8_t> &terrain) {
    std::ifstream file(MAPS_PATH "data.yaml");
    YAML::Node config = YAML::Load(file);
    rows = config["map"]["rows"].as<int>();
    columns = config["map"]["columns"].as<int>();

    map = std::vector<std::vector<ServerCell *>>(
            rows, std::vector<ServerCell *>(columns));
    entityId = 1;

    for (YAML::Node cell : config["map"]["cells"]) {
        auto row = cell["pos"][1].as<int>();
        auto column = cell["pos"][0].as<int>();
        auto _terrain = cell["terrain"].as<std::string>();

        for (YAML::Node building : cell["buildings"]) {
            auto name = building["name"].as<std::string>();
            if (name == "Construction Center") {
                construction_centers.push({row, column});
            }
        }

        if (_terrain == YAML_SAND) {
            auto spice = cell["seed"].as<unsigned int>();
            map[row][column] = new SandCell({row, column}, spice);
            if (spice > 0 && spice < 50) {
                spice_cells.emplace_back(row, column);
                terrain.push_back(TERRAIN_SPICE_LOW);
            } else if (spice > 50) {
                spice_cells.emplace_back(row, column);
                terrain.push_back(TERRAIN_SPICE_HIGH);
            } else {
                terrain.push_back(TERRAIN_SAND);
            }
        } else if (_terrain == YAML_DUNE) {
            map[row][column] = new DunesCell({row, column});
            terrain.push_back(TERRAIN_DUNES);
        } else if (_terrain == YAML_ROCK) {
            map[row][column] = new RockCell({row, column});
            terrain.push_back(TERRAIN_ROCKS);
        } else if (_terrain == YAML_TOP) {
            map[row][column] = new TopsCell({row, column});
            terrain.push_back(TERRAIN_TOPS);
        } else if (_terrain == YAML_CLIFF) {
            map[row][column] = new CliffsCell({row, column});
            terrain.push_back(TERRAIN_CLIFFS);
        } else {
            throw std::runtime_error("Unknown terrain");
        }
    }
}

bool ServerMap::validPosition(coordenada_t position) const {
    return position.first >= 0 && position.first < rows
           && position.second >= 0 && position.second < columns;
}

int ServerMap::getRows() const {
    return rows;
}

int ServerMap::getColumns() const {
    return columns;
}

void ServerMap::build(int playerId, coordenada_t &position, int buildingType, int size_x, int size_y) {
    int x = position.first, y = position.second;

    // Reviso que haya suficiente espacio
    int aux = 0;
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            if ((x + i) <= rows && (y + j) <= columns && !map[x + i][y + j]->occupied) {
                aux++;
            }
        }
    }

    // Reviso que no haya otro edificio a 5 celdas de distancia
    for (int i = -5; i < 5 + size_y; i++) {
        for (int j = -5; j < 5 + size_x; j++) {
            if ( (x + i) >= 0 && (y + j) >= 0 && (x + i) < rows && (y + j) < columns) {
                for (auto & [id, player] : players) {
                    coordenada_t location(x + i, y + j);
                    if (player.checkForBuilding(location))
                        return;
                }
            }
        }
    }

    bool done = players[playerId].addBuilding(entityId, buildingType, position);
    if (done) {
        for (int i = 0; i < size_y; i++) {
            for (int j = 0; j < size_x; j++) {
                map[x + i][y + j]->occupied = true;
            }
        }
        entityId++;
    }
}

void ServerMap::attackEnemy(int playerId, int unitId, int enemyId) {
    int enemyPlayer = findPlayerByUnitId(enemyId);
    if (enemyPlayer >= 0 && enemyPlayer != playerId)
        players.at(playerId).getUnit(unitId)->setTarget(enemyPlayer, enemyId);
}

int ServerMap::findPlayerByUnitId(int unitId) {
    for (auto & [playerId, player] : players) {
        if (player.owns(unitId))
            return playerId;
    }
    return -1;
}

void ServerMap::unitAttackReset() {
    for (auto & [playerId, player] : players) {
        player.unitAttackReset();
    }
}

void ServerMap::buildConstructionCenter(int playerId) {
    players.insert(std::pair<int, Player> (playerId, Player(playerId, 0)));

    if (!construction_centers.empty()) {
        coordenada_t position = construction_centers.front();
        // No lo pongo en en el metodo createBuilding para que si juega eldipa no se ponga
        // 18 centros de construccion y gane siempre
        build(playerId, position, BUILDING_CONSTRUCTION_CENTER, 3, 3);
        construction_centers.pop();
    } else {
        throw std::runtime_error("Game is full");
    }
}

coordenada_t ServerMap::findClosestHarvestableCell(coordenada_t position) {
    std::vector<coordenada_t> valid_positions;
    for (int i = -5; i <= 5; i++) {
        for (int j = -5; j <= 5; j++) {
            coordenada_t aux(position.first + i, position.second + j);
            if (validPosition(aux)) {
                if (map[aux.first][aux.second]->harvestable()) {
                    valid_positions.push_back(aux);
                }
            }
        }
    }

    coordenada_t closest(-1, -1);
    double distance = INFINITY;

    for (auto & coord : valid_positions) {
        auto _distance = calculateDistance(position, coord);
        if (_distance < distance) {
            distance = _distance;
            closest = coord;
        }
    }

    return std::move(closest);
}

double ServerMap::calculateDistance(coordenada_t unit1, coordenada_t unit2) {
    int x1 = unit1.first, y1 = unit1.second;
    int x2 = unit2.first, y2 = unit2.second;

    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2) * 1.0);
}

void ServerMap::addTerrainData(Snapshot &snapshot) {
    for (auto coord : spice_cells) {
        if (map[coord.first][coord.second]->harvestable()) {
            snapshot.addHarvestZone(coord, map[coord.first][coord.second]->getSpice());
        }
    }
}
