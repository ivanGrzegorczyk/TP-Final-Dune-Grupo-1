#ifndef TP_FINAL_DUNE_GRUPO_1_UPDATEUNIT_H
#define TP_FINAL_DUNE_GRUPO_1_UPDATEUNIT_H
#include "Response.h"

class UpdateUnit : public Response {
private:
    int player;
    int type;
    int characterId;
    coordenada_t coord;
public:
    UpdateUnit(int player, int type, int characterId, coordenada_t coord);
    void modify(MapUi &mapUi) override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_UPDATEUNIT_H
