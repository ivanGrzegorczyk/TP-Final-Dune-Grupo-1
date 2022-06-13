#include "../headers/SpawnUnitEvent.h"

SpawnUnitEvent::SpawnUnitEvent(int playerId, int unit) :
ServerEvent(playerId), unitType(unit) {}

void SpawnUnitEvent::performEvent(Server *server) {
    server->spawnUnit(playerId, unitType);
}
