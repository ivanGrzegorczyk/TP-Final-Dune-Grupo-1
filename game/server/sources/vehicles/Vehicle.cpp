#include "server/headers/vehicles/Vehicle.h"

Vehicle::Vehicle(int id, int hp, int range, int speed, int type, unsigned int cost, coordenada_t coord) :
        MovableEntity(id, hp, type, speed, coord), range(range), cost(cost) {}
