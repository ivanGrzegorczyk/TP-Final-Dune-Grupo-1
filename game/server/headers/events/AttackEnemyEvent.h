#ifndef ATTACKENEMYEVENT_H_
#define ATTACKENEMYEVENT_H_

#include "ServerEvent.h"

class AttackEnemyEvent : public ServerEvent {
public:
    int unitId;
    int enemyId;

    AttackEnemyEvent(int playerId, int unitId, int enemyId);

    void performEvent(ServerMap &map) override;
};

#endif  // ATTACKENEMYEVENT_H_
