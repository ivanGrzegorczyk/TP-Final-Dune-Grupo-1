#ifndef TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H
#define TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H

#include "client/headers/Attacker.h"
#include "client/headers/Damageable.h"
#include "common/headers/Entity.h"
#include "client/headers/SdlEntity.h"

class ClientUnit : public Entity, SdlEntity, Attacker, public Damageable {
    int range;
    int speed;
public:
    int playerId;
    ClientUnit(int playerId, int id, double hp, int range, int speed, int type, coordenada_t coord);
    void setPosition(coordenada_t newPosition);
};


#endif //TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H
