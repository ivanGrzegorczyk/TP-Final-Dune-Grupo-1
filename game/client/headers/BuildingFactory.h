#ifndef TP_FINAL_DUNE_GRUPO_1_BUILDINGFACTORY_H
#define TP_FINAL_DUNE_GRUPO_1_BUILDINGFACTORY_H

#include "SDL2pp/SDL2pp.hh"
#include "SdlEntity.h"
#include "common/headers/Constantes.h"

using namespace SDL2pp;

class BuildingFactory {
public:
    BuildingFactory() = default;
    SdlEntity * createBuilding(int type, int id, coordenada_t coord,Renderer &render);
};


#endif //TP_FINAL_DUNE_GRUPO_1_BUILDINGFACTORY_H
