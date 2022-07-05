#ifndef TP_FINAL_DUNE_GRUPO_1_UPDATETERRAIN_H
#define TP_FINAL_DUNE_GRUPO_1_UPDATETERRAIN_H

#include "Event.h"
#include "MapUi.h"

class UpdateTerrain : public Event {
private:
    int player;
    coordenada_t coord;
    int soil;
public:
    UpdateTerrain(int player, int position_x, int position_y, int soil) : 
        coord({position_x, position_y}), player(player), soil(soil) {}
    void modify(MapUi *mapUi) override {
        mapUi->updateTerrain(coord, soil);
    }
};


#endif //TP_FINAL_DUNE_GRUPO_1_UPDATETERRAIN_H
