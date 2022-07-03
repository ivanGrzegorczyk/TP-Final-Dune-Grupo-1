#include "server/headers/events/AttackEnemyEvent.h"

AttackEnemyEvent::AttackEnemyEvent(int playerId, int unitId, int enemyId) :
        ServerEvent(playerId), unitId(unitId), enemyId(enemyId) {}

void AttackEnemyEvent::performEvent(ServerMap &map) {
    map.attackEnemy(playerId, unitId, enemyId);
}
