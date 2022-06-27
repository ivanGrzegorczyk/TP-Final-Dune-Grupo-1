#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <memory>
#include "common/headers/Entity.h"

class Vehicle : public Entity {
protected:
    unsigned int range;
    unsigned int speed;
    unsigned int cost;

public:
    Vehicle(int id, int hp, int range, int speed, int type, unsigned int cost, coordenada_t coord);

    virtual std::shared_ptr<Vehicle> copy() = 0;

    virtual ~Vehicle() = default;
};

#endif  // VEHICLE_H_
