
#include "client/headers/building_type/BuildingType.h"
using namespace SDL2pp;
// TODO make this and Building inherit from the same class that has hp, type, size, energy and cost
BuildingType::BuildingType(int hp, int type, int energy, int cost, coordenada_t size, std::string texture_name) 
:   hp(hp), 
    type(type), 
    size(size), 
    energy(energy), 
    cost(cost), 
    texture_file(std::string(DATA_PATH "/") + texture_name ) {}


