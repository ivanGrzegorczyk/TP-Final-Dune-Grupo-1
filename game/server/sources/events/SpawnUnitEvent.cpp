#include "../../headers/events/SpawnUnitEvent.h"

#include <utility>

SpawnUnitEvent::SpawnUnitEvent(int playerId, int unit, coordenada_t position) :
ServerEvent(playerId), unitType(unit), position(std::move(position)) {}

void SpawnUnitEvent::performEvent(ServerMap &map) {
    map.spawnUnit(playerId, unitType, position);
}
