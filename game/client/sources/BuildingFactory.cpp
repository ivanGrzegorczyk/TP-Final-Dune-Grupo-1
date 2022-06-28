#include <map>
#include "client/headers/BuildingFactory.h"
#include "client/headers/BarracksUi.h"

SdlEntity *BuildingFactory::createBuilding(int player, int type, int id, coordenada_t coord,
                                           Renderer &render, std::map<int, std::map<int, SdlEntity*>> &buildings) {
    SdlEntity* building = nullptr;
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
