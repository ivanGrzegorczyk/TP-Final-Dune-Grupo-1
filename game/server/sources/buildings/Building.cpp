#include <vector>
#include "server/headers/buildings/Building.h"

Building::Building(int id, int hp, int type, coordenada_t coords, int energy, int cost) :
Entity(id, hp, type, coords), energy(energy), cost(cost) {}