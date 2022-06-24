#ifndef TP_FINAL_DUNE_GRUPO_1_UPDATEUNIT_H
#define TP_FINAL_DUNE_GRUPO_1_UPDATEUNIT_H

#include "Event.h"
#include "common/headers/Constantes.h"
#include "MapUi.h"

class UpdateUnit : public Event {
private:
    int player;
    int type;
    int characterId;
    coordenada_t coord;
public:
    UpdateUnit(int player, int type, int characterId, coordenada_t coord);
    void modify(MapUi *mapUi) override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_UPDATEUNIT_H
