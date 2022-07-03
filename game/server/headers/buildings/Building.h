#ifndef BUILDING_H_
#define BUILDING_H_

#include <memory>
#include "server/headers/model/ServerEntity.h"
#include "common/headers/Constantes.h"

class Building: public ServerEntity {
protected:
    unsigned int energy;
    unsigned int cost;

public:
    Building(int id, int hp, int type, coordenada_t coords, unsigned int energy, unsigned int cost);
    virtual std::shared_ptr<Building> copy() = 0;

    virtual ~Building() = default;
};

#endif  // BUILDING_H_
