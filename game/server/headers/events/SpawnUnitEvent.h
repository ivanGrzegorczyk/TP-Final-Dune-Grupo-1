#ifndef SPAWNUNITEVENT_H_
#define SPAWNUNITEVENT_H_

#include "ServerEvent.h"

class SpawnUnitEvent : public ServerEvent {
public:
    int unitType;
    coordenada_t position;

    SpawnUnitEvent(int playerId, int unit, coordenada_t position);

    void performEvent(ServerMap &map) override;
};

#endif   // SPAWNUNITEVENT_H_
