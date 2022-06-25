#include "client/headers/BuildingFactory.h"
#include "client/headers/BarracksUi.h"

SdlEntity *BuildingFactory::createBuilding(int type, int id, coordenada_t coord, Renderer &render) {
    SdlEntity* building;
    switch (type) {
        case BUILDING_BARRACKS:
            building = new BarracksUi(coord, id, render);
            break;
        default:
            building = nullptr;
            break;
    }
    return  building;
}
