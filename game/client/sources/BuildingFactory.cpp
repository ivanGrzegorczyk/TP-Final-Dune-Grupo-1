#include "client/headers/BuildingFactory.h"
#include "client/headers/BarracksUi.h"

// TODO this reads from the yaml instead
std::vector<BuildingType> BuildingFactory::createBuildingTypes() {
    std::vector<BuildingType> building_types;
    coordenada_t size = {2,2};
    building_types.push_back(BuildingType(1,2,3,4,size, std::string("Barracks.png")));
    building_types.push_back(BuildingType(5,6,7,8, size, std::string("Barracks.png")));
    building_types.push_back(BuildingType(20,20,40,40, size, std::string("Barracks.png")));
    return building_types;
}

SdlEntity *BuildingFactory::createBuilding(int player, int type, int id, coordenada_t coord, Renderer &render) {
    SdlEntity* building;
    switch (type) {
        case BUILDING_BARRACKS:
            building = new BarracksUi(player,coord, id, render);
            break;
        default:
            building = nullptr;
            break;
    }
    return  building;
}
