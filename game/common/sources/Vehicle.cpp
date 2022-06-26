#include "common/headers/Vehicle.h"

Vehicle::Vehicle(int playerId, int id, int hp, int range, int speed, int type, unsigned int cost, coordenada_t coord) :
        Entity(playerId, id, hp, type, coord), range(range), speed(speed), cost(cost) {}

