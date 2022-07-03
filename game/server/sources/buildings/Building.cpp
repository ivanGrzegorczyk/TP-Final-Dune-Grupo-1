#include <vector>
#include "server/headers/buildings/Building.h"

Building::Building(int id, int hp, int type, coordenada_t coords, unsigned int energy, unsigned int cost) :
        ServerEntity(id, hp, type, coords), energy(energy), cost(cost) {}
