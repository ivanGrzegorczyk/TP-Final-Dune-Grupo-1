#ifndef CREATEBUILDINGEVENT_H_
#define CREATEBUILDINGEVENT_H_

#include "ServerEvent.h"

class CreateBuildingEvent : public ServerEvent {
public:
    int buildingType;
    coordenada_t coords;

    CreateBuildingEvent(int playerId, int buildingType, coordenada_t coords);

    void performEvent(ServerMap &map) override;
};

#endif  // CREATEBUILDINGEVENT_H_
