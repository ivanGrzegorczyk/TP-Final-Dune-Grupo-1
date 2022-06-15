#include "../../headers/events/RepositionEvent.h"

RepositionEvent::RepositionEvent(int playerId, int unitId, coordenada_t goal) :
ServerEvent(playerId), unitId(unitId), goal(std::move(goal)) {}

void RepositionEvent::performEvent(ServerMap &map, BlockingQueue<bool> &queue) {
    int updates;
    map.reposition(playerId, unitId, goal, updates);
    for (int i = 0; i < updates; i++)
        queue.push(true);
}
