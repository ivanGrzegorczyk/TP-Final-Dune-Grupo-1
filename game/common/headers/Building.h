#ifndef BUILDING_H_
#define BUILDING_H_

#include "Entity.h"

class Building: public Entity {
protected:
    std::vector<coordenada_t> coords;

public:
    virtual ~Building() = 0;
};

#endif  // BUILDING_H_
