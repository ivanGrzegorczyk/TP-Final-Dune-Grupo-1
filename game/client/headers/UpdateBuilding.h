#ifndef TP_FINAL_DUNE_GRUPO_1_UPDATEBUILDING_H
#define TP_FINAL_DUNE_GRUPO_1_UPDATEBUILDING_H

#include "Event.h"
#include "MapUi.h"

class UpdateBuilding : public Event {
private:
    int player;
    int type;
    int buildingId;
    coordenada_t coord;
public:
    UpdateBuilding(int player, int type, int buildingId, coordenada_t coord);
    void modify(MapUi *mapUi) override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_UPDATEBUILDING_H
