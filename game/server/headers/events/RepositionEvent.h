#ifndef REPOSITIONEVENT_H_
#define REPOSITIONEVENT_H_

#include <utility>
#include "server/headers/model/ServerEntity.h"
#include "ServerEvent.h"

class RepositionEvent : public ServerEvent {
public:
    int unitId;
    coordenada_t goal;

    RepositionEvent(int playerId, int unitId, coordenada_t goal);

    void performEvent(ServerMap &map) override;
};

#endif  // REPOSITIONEVENT_H_
