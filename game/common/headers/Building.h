#ifndef BUILDING_H_
#define BUILDING_H_

#include "Entity.h"
#include "Constantes.h"

class Building: public Entity {
public:
    Building(int id, double hp, int type, coordenada_t coords);
};

#endif  // BUILDING_H_
