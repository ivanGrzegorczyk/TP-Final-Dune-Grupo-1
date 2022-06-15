#ifndef BUILDING_H_
#define BUILDING_H_

#include "Entity.h"

class Building: public Entity {
private:
    std::vector<coordenada_t> id;

public:
    virtual ~Building() = 0;
};

#endif  // BUILDING_H_
