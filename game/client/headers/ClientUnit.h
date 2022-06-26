#ifndef TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H
#define TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H


#include "common/headers/Entity.h"

class ClientUnit : public Entity {
    int range;
    int speed;
public:
    ClientUnit(int playerId, int id, double hp, int range, int speed, int type, coordenada_t coord);
    void setPosition(coordenada_t newPosition);
};


#endif //TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H
