#include "client/headers/UpdateBuilding.h"
#include "client/headers/building_type/BuildingType.h"
#include <utility>

void UpdateBuilding::modify(MapUi *mapUi) {
    std::shared_ptr<BuildingType> _type = mapUi->getBuildingType(-1);
    mapUi->updateBuilding(player, type, _type, coord);
}

UpdateBuilding::UpdateBuilding(int player, int type, int buildingId, coordenada_t coord) :
    player(player),type(type), buildingId(buildingId), coord(std::move(coord)) {
}
