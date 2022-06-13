#include "../headers/RepositionEvent.h"

RepositionEvent::RepositionEvent(int playerId, int unitId, coordenada_t goal) :
ServerEvent(playerId), unitId(unitId), goal(std::move(goal)) {}

void RepositionEvent::performEvent(Server *server) {
    server->repositionUnit(playerId, unitId, goal);
}

