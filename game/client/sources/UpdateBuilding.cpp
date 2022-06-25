#include "client/headers/UpdateBuilding.h"

#include <utility>

void UpdateBuilding::modify(MapUi *mapUi) {
    mapUi->updateBuilding(player, type, buildingId, coord);
}

UpdateBuilding::UpdateBuilding(int player, int type, int buildingId, coordenada_t coord) :
    player(player),type(type), buildingId(buildingId), coord(std::move(coord)) {
}
