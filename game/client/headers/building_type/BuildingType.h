#ifndef TP_FINAL_DUNE_GRUPO_1_BuildingType_H
#define TP_FINAL_DUNE_GRUPO_1_BuildingType_H
#include "SDL2pp/SDL2pp.hh"
#include "common/headers/Constantes.h"
using namespace SDL2pp;

class BuildingType {
private:
    int _hp;
    std::string _type;
    int _energy;
    int _code;
    int _cost;
    coordenada_t _size;
    Texture _texture;
public:
    explicit BuildingType(
            int hp, std::string& type, int energy, int code,
            int cost, coordenada_t size,
            Texture&& texture);
    int hp() const {
        return this->_hp;
    };
    std::string type() const {
        return this->_type;
    };
    int energy() const {
        return this->_energy;
    };
    int cost() const {
        return this->_cost;
    };
    int code() const {
        return this->_code;
    };
    Texture& texture() {
        return _texture;
    };
};


#endif //TP_FINAL_DUNE_GRUPO_1_BuildingType_H
