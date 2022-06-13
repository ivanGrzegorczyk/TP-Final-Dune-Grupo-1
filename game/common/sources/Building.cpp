#include <utility>
#include <vector>
#include "../headers/Building.h"

Building::Building(int id, double hp, std::vector <coordenada_t> coords) : Entity(id, hp), coords(std::move(coords)) {}

