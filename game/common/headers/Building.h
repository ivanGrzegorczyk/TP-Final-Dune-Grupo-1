#ifndef BUILDING_H_
#define BUILDING_H_

#include "Entity.h"
#include "Constantes.h"

class Building: public Entity {
protected:
    std::vector<coordenada_t> coords;

public:
    Building(int id, double hp, std::vector<coordenada_t> coords);
};

#endif  // BUILDING_H_
