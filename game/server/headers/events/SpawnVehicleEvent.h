#ifndef SPAWNVEHICLEEVENT_H_
#define SPAWNVEHICLEEVENT_H_


#include "ServerEvent.h"

class SpawnVehicleEvent : public ServerEvent {
public:
    int vehicleType;
    coordenada_t position;

    SpawnVehicleEvent(int playerId, int vehicle, coordenada_t position);

    void performEvent(ServerMap &map) override;
};


#endif  // SPAWNVEHICLEEVENT_H_
