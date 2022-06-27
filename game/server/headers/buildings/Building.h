#ifndef BUILDING_H_
#define BUILDING_H_

#include <memory>
#include "common/headers/Entity.h"
#include "common/headers/Constantes.h"

class Building: public Entity {
protected:
    int energy;
    int cost;

public:
    Building(int id, int hp, int type, coordenada_t coords, int energy, int cost);
    virtual std::shared_ptr<Building> copy() = 0;

    virtual ~Building() = default;
};

#endif  // BUILDING_H_
