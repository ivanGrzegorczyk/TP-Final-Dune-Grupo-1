#include "server/headers/events/SpawnVehicleEvent.h"

SpawnVehicleEvent::SpawnVehicleEvent(int playerId, int vehicle, coordenada_t position) :
        ServerEvent(playerId), vehicleType(vehicle), position(std::move(position)) {}

void SpawnVehicleEvent::performEvent(ServerMap &map) {
    map.spawnVehicle(playerId, vehicleType, position);
}