#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "Entity.h"

class Vehicle : public Entity {
protected:
    unsigned int range;
    unsigned int speed;
    unsigned int cost;

public:
    Vehicle(int id, int hp, int range, int speed, int type, unsigned int cost, coordenada_t coord);
};

#endif  // VEHICLE_H_
