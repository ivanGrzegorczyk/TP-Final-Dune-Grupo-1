#include "client/headers/building_type/BuildingType.h"
using namespace SDL2pp;
// TODO make this and Building inherit from the same class that has hp, type, size, energy and cost
BuildingType::BuildingType(int hp, std::string& type, int energy, int cost, coordenada_t size, Texture&& texture) 
:   _hp(hp), 
    _type(type), 
    _size(size), 
    _energy(energy), 
    _cost(cost), 
    _texture(std::move(texture)) {}


