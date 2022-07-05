#ifndef SPAWNUNITEVENT_H_
#define SPAWNUNITEVENT_H_

#include "ServerEvent.h"

class SpawnUnitEvent : public ServerEvent {
public:
    int unitType;
    int buildingId;

    SpawnUnitEvent(int playerId, int unit, int buildingId);

    void performEvent(ServerMap &map) override;
};

#endif   // SPAWNUNITEVENT_H_
