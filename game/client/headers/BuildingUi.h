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
    coordenada_t coord;
    Rect location;
public:
    BuildingUi(
        int player, 
        int buildingId,
        std::shared_ptr<BuildingType> type, 
        Renderer &rdr, 
        coordenada_t coord, 
        Point size,
        Point map_center) ;
    void render() override;
    void update() override;

};


#endif //TP_FINAL_DUNE_GRUPO_1_BuildingUi_H
