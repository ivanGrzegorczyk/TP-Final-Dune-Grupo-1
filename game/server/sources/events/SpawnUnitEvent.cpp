#include "../../headers/events/SpawnUnitEvent.h"

SpawnUnitEvent::SpawnUnitEvent(int playerId, int unit) :
ServerEvent(playerId), unitType(unit) {}

void SpawnUnitEvent::performEvent(ServerMap &map) {
    map.spawnUnit(playerId, unitType);
}
