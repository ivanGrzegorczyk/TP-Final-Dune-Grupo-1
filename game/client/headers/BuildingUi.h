#ifndef TP_FINAL_DUNE_GRUPO_1_BuildingUi_H
#define TP_FINAL_DUNE_GRUPO_1_BuildingUi_H

#include "SDL2pp/SDL2pp.hh"
#include "../../common/headers/Constantes.h"
#include "client/headers/building_type/BuildingType.h"
#include "client/headers/SdlEntity.h"
#include <memory>

using namespace SDL2pp;

class BuildingUi : public SdlEntity{
private:
    std::shared_ptr<BuildingType> type;
    Renderer &renderer;
    Rect location;
public:
    BuildingUi(
        std::shared_ptr<BuildingType> t, 
        Renderer &renderer, 
        coordenada_t location);
    void render() override;
    void update() override;

};


#endif //TP_FINAL_DUNE_GRUPO_1_BuildingUi_H
