#ifndef TP_FINAL_DUNE_GRUPO_1_UnitType_H
#define TP_FINAL_DUNE_GRUPO_1_UnitType_H
#include "SDL2pp/SDL2pp.hh"
#include "common/headers/Constantes.h"
using namespace SDL2pp;

class UnitType {
private:
public:
    std::string _name;
    int _id;
    int _hp;
    float _speed;
    float _training_time;
    int _range;
    int _cost;
    Texture _texture;
    explicit UnitType(std::string name, 
            int id,
            int hp, float speed, 
            float training_time, int range,
            int cost, Texture&& texture) ;
};


#endif //TP_FINAL_DUNE_GRUPO_1_UnitType_H
