#include "../../headers/events/CreateBuildingEvent.h"

#include <utility>

CreateBuildingEvent::CreateBuildingEvent(int playerId, int buildingType, coordenada_t coords) :
ServerEvent(playerId), buildingType(buildingType), coords(std::move(coords)) {}

void CreateBuildingEvent::performEvent(ServerMap &map) {
    map.createBuilding(playerId, buildingType, coords);
}

