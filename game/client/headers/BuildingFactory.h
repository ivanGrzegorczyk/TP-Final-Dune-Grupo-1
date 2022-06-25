#ifndef TP_FINAL_DUNE_GRUPO_1_BUILDINGFACTORY_H
#define TP_FINAL_DUNE_GRUPO_1_BUILDINGFACTORY_H


#include "common/headers/Building.h"
#include "SDL2pp/SDL2pp.hh"

using namespace SDL2pp;

class BuildingFactory {
public:
    BuildingFactory() = default;
    Building* createBuilding(int type, int id, coordenada_t coord,Renderer &render);
};


#endif //TP_FINAL_DUNE_GRUPO_1_BUILDINGFACTORY_H
