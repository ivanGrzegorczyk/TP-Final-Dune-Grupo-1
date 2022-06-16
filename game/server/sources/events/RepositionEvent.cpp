#include "../../headers/events/RepositionEvent.h"

RepositionEvent::RepositionEvent(int playerId, int unitId, coordenada_t goal) :
ServerEvent(playerId), unitId(unitId), goal(std::move(goal)) {
    std::cout << "Constructor de RepositionEvent" << std::endl;
    std::cout << "playerId: " << playerId << std::endl;
    std::cout << "unitId: " << unitId <<  std::endl;
    std::cout << "X: " << this->goal.first << std::endl;
    std::cout << "Y: " << this->goal.second << std::endl;
}

void RepositionEvent::performEvent(ServerMap &map) {
    map.reposition(playerId, unitId, goal);
}
