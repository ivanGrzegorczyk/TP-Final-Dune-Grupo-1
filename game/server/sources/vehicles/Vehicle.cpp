#include "server/headers/vehicles/Vehicle.h"

Vehicle::Vehicle(int id, int hp, int range, int speed, int type, unsigned int cost, coordenada_t coord) :
        ServerEntity(id, hp, type, coord), range(range), speed(speed), cost(cost) {}

