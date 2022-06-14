#ifndef CREATEBUILDINGEVENT_H_
#define CREATEBUILDINGEVENT_H_

#include "ServerEvent.h"

class CreateBuildingEvent : public ServerEvent {
public:
    int buildingType;
    std::vector<coordenada_t> coords;

    CreateBuildingEvent(int playerId, int buildingType, std::vector<coordenada_t> coords);

    void performEvent(Server *server) override;
};

#endif  // CREATEBUILDINGEVENT_H_