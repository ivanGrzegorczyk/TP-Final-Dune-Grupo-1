#include "server/headers/vehicles/Vehicle.h"

Vehicle::Vehicle(int id, int hp, int range, int speed, int type, unsigned int cost, coordenada_t coord) :
        Entity(id, hp, type, coord), range(range), speed(speed), cost(cost) {}

