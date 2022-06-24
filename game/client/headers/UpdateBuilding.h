#ifndef TP_FINAL_DUNE_GRUPO_1_UPDATEBUILDING_H
#define TP_FINAL_DUNE_GRUPO_1_UPDATEBUILDING_H

#include "Event.h"
#include "MapUi.h"

class UpdateBuilding : public Event {
public:
    void modify(MapUi *mapUi) override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_UPDATEBUILDING_H
