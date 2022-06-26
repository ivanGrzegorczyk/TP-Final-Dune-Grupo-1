#include <utility>
#include <vector>
#include "../headers/Building.h"

Building::Building(int playerId, int id, int hp, int type, coordenada_t coords, int energy, int cost) :
Entity(playerId, id, hp, type, coords), energy(energy), cost(cost) {}
