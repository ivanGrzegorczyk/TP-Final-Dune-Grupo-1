#ifndef SERVERMAP_H_
#define SERVERMAP_H_

#include <memory>
#include <map>

#include "ServerCell.h"
#include "Navigator.h"

class ServerMap {
private:
    // Key: id del jugador, valor mapa con key id de la entidad y valor un puntero a la entidad
    std::map<int, std::map<int, std::shared_ptr<Building>>> buildings;
    std::map<int, std::map<int, std::shared_ptr<Unit>>> units;
    std::vector<std::vector<ServerCell>> map;
    int entityId;

    std::stack<coordenada_t> A_star(coordenada_t start, coordenada_t end);
    void addUnitData(int playerId, std::vector<uint16_t> &vec);
    void addBuildingData(int playerId, std::vector<uint16_t> &vec);

public:
    ServerMap(int rows, int columns);

    void reposition(int playerId, int unitId, coordenada_t goal);

    void spawnUnit(int playerId, int unit, coordenada_t position);

    bool updateUnitPositions();

    void createBuilding(int playerId, int buildingType, coordenada_t position);

    void addSnapshotData(std::vector<uint16_t> &snapshot);

    void initializeTerrain();
};

#endif  // SERVERMAP_H_
