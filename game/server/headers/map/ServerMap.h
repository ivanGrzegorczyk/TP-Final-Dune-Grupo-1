#ifndef SERVERMAP_H_
#define SERVERMAP_H_

#include <memory>
#include <map>
#include <mutex>

#include "ServerCell.h"
#include "Navigator.h"
#include "server/headers/model/Player.h"
#include "server/headers/model/Snapshot.h"

class ServerMap {
private:
    int rows;
    int columns;
    // Key: id y valor jugador
    std::map<int, Player> players;
    std::vector<std::vector<ServerCell *>> map;
    int entityId;

    std::stack<coordenada_t> A_star(coordenada_t start, coordenada_t end);

    void build(int playerId, coordenada_t &position, int buildingType, int size_x, int size_y);

public:

    ServerMap() = default;

    ServerMap(int rows, int columns);

    void reposition(int playerId, int unitId, coordenada_t goal, bool userMoved);

    void spawnUnit(int playerId, int unit, coordenada_t position);

    void updateUnitsPosition();

    void unitCheck();

    void createBuilding(int playerId, int buildingType, coordenada_t position);

    void addSnapshotData(Snapshot &snapshot);

    void initializeTerrain(std::vector<uint8_t> &terrain);

    bool validPosition(coordenada_t position) const;

    int getRows() const;

    int getColumns() const;

    void attackEnemy(int playerId, int unitId, int enemyId);

    int findPlayerByUnitId(int unitId);
};

#endif  // SERVERMAP_H_
