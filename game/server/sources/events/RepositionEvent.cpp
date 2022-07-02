#include "../../headers/events/RepositionEvent.h"

RepositionEvent::RepositionEvent(int playerId, int unitId, coordenada_t goal) :
ServerEvent(playerId), unitId(unitId), goal(std::move(goal)) {}

void RepositionEvent::performEvent(ServerMap &map) {
    map.reposition(playerId, unitId, goal, true);
}
