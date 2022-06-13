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
    std::map<int, std::map<int, std::shared_ptr<Units>>> units;
    std::vector<std::vector<ServerCell>> map;

    std::stack<coordenada_t> A_star(coordenada_t start, coordenada_t end);

public:
    ServerMap(int rows, int columns);

    bool reposition(int playerId, int id, coordenada_t goal);

    void spawnUnit(int playerId, int unit);
};

#endif  // SERVERMAP_H_
