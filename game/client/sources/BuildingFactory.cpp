#include <map>
#include "client/headers/BuildingFactory.h"
#include "client/headers/BarracksUi.h"

// TODO this reads from the yaml instead
std::vector<BuildingType> BuildingFactory::createBuildingTypes(Renderer &render) {
    std::vector<BuildingType> building_types;
    coordenada_t size = {2,2};
    std::string texture_name = std::string("Barracks.png");
    Surface surface(std::string(DATA_PATH "/") + texture_name );
    Texture texture(render, surface);
    Texture texture2(render, surface);
    Texture texture3(render, surface);
    std::string lol ("lol");
    building_types.push_back(BuildingType(1,lol,3,4,size, std::move(texture)));
    building_types.push_back(BuildingType(5,lol,7,8, size,  std::move(texture2)));
    building_types.push_back(BuildingType(20,lol,40,40, size, std::move(texture3)));
    return building_types;
}

SdlEntity *BuildingFactory::createBuilding(int player, int type, int id, coordenada_t coord, Renderer &render) {
    SdlEntity* building;
    switch (type) {
        case BUILDING_BARRACKS:
            //buildings[player].insert(std::make_pair<int, SdlEntity*>(int{id}, new BarracksUi(player,coord, id, render)));
            break;
        default:
            building = nullptr;
            break;
    }
    return building;
}
