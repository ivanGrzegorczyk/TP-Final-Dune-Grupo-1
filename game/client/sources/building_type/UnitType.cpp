#include "client/headers/building_type/UnitType.h"
using namespace SDL2pp;
// TODO make this and Building inherit from the same class that has hp, type, size, energy and cost
UnitType::UnitType(std::string name,
                   int id,
                   int hp, float speed,
                   float training_time, int range,
                   int cost, Texture&& texture)
        :   _id(id),
            _name(name),
            _hp(hp),
            _speed(speed),
            _training_time(training_time),
            _cost(cost),
            _range(range),
            _texture(std::move(texture)) {}


