#include <utility>
#include <vector>
#include "../headers/Building.h"

Building::Building(int id, double hp, int type, std::vector<coordenada_t> coords) : Entity(id, hp, type), coords(std::move(coords)) {}

