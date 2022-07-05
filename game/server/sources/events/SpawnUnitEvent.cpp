#include "../../headers/events/SpawnUnitEvent.h"

#include <utility>

SpawnUnitEvent::SpawnUnitEvent(int playerId, int unit, int buildingId) :
ServerEvent(playerId), unitType(unit), buildingId(buildingId) {}

void SpawnUnitEvent::performEvent(ServerMap &map) {
    map.spawnUnit(playerId, unitType, buildingId);
}
