#ifndef TP_FINAL_DUNE_GRUPO_1_BARRACKSUI_H
#define TP_FINAL_DUNE_GRUPO_1_BARRACKSUI_H

#include "SDL2pp/SDL2pp.hh"
#include "client/headers/building_type/BuildingType.h"
#include "common/headers/Building.h"
#include "client/headers/SdlEntity.h"
#include <memory>
using namespace SDL2pp;

class BarracksUi : public SdlEntity{
private:
    std::shared_ptr<BuildingType> type;
    Rect location;
    Renderer &renderer;
public:
    explicit BarracksUi(
        int player, 
        std::shared_ptr<BuildingType> type, 
        Renderer &rdr, 
        coordenada_t coord, 
        Point map_center = Point(0,0));
    void render() override;
    void update() override;

};


#endif //TP_FINAL_DUNE_GRUPO_1_BARRACKSUI_H
