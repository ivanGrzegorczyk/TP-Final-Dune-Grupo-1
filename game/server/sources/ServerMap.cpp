#include "../headers/ServerMap.h"
#include "../../common/headers/Constantes.h"
#include "../../common/headers/LightInfantry.h"

ServerMap::ServerMap(int rows, int columns) :
map(rows, std::vector<ServerCell>(columns)) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j].id = {i, j};
        }
    }
}

std::stack<coordenada_t> ServerMap::A_star(
        coordenada_t start, coordenada_t end) {
    Navigator navigator(map);
    return navigator.A_star(start, end);
}

bool ServerMap::reposition(int playerId, int unitId, coordenada_t goal) {
    try {
        if (units.at(playerId).at(unitId)->getPosition() == goal)
            return false;

        units.at(playerId).at(unitId)->setPath(
                A_star(units.at(playerId).at(unitId)->getPosition(), goal));
        return true;  // TODO Revisar caso en el que no hay un camino posible
    } catch(const std::out_of_range &e) {
        return false;
    }
}

void ServerMap::spawnUnit(int playerId, int unit) {
    int unityId = units.size() + 1; // TODO Que pasa si se elimina alguna unidad? Que id correspondería?
    if (unit == LIGHT_INFANTRY)
        units.at(playerId).insert(std::pair<int, Units *> (
                unityId, new LightInfantry(unityId, coordenada_t{1, 1})));
}
