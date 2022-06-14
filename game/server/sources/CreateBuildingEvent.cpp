#include "../headers/CreateBuildingEvent.h"

#include <utility>

CreateBuildingEvent::CreateBuildingEvent(int playerId, int buildingType, coordenada_t coords) :
ServerEvent(playerId), buildingType(buildingType), coords(std::move(coords)) {}

void CreateBuildingEvent::performEvent(Server *server) {
    server->createBuilding(playerId, buildingType, coords);
}

