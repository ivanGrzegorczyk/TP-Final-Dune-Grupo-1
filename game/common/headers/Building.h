#ifndef BUILDING_H_
#define BUILDING_H_

#include "Entity.h"
#include "Constantes.h"

class Building: public Entity {
protected:
    int energy;
    int cost;

public:
    Building(int playerId, int id, int hp, int type, coordenada_t coords, int energy, int cost);
};

#endif  // BUILDING_H_
