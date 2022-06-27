#include "client/headers/BuildingFactory.h"
#include "client/headers/BarracksUi.h"

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
