#ifndef SPAWNUNITEVENT_H_
#define SPAWNUNITEVENT_H_

#include "ServerEvent.h"

class SpawnUnitEvent : public ServerEvent {
public:
    int unitType;

    SpawnUnitEvent(int playerId, int unit);

    void performEvent(Server *server) override;
};

#endif   // SPAWNUNITEVENT_H_
