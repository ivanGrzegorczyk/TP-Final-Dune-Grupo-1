#include "../headers/RepositionEvent.h"

void RepositionEvent::performEvent(Server *server) {
    server->repositionUnity(unitId, goal);
}

RepositionEvent::RepositionEvent(int id, coordenada_t goal) :
        unitId(id), goal(std::move(goal)) {}

