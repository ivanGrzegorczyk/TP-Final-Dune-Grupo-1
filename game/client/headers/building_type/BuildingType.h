#ifndef TP_FINAL_DUNE_GRUPO_1_BuildingType_H
#define TP_FINAL_DUNE_GRUPO_1_BuildingType_H
#include "SDL2pp/SDL2pp.hh"
#include "common/headers/Constantes.h"
using namespace SDL2pp;

class BuildingType {
private:
    int hp;
    coordenada_t size;
    int energy;
    int cost;
    Surface texture_file;
    Rect texture_location;
public:
    int type;
    explicit BuildingType(int hp, int type, int energy, int cost, coordenada_t size, std::string texture_name);
};


#endif //TP_FINAL_DUNE_GRUPO_1_BuildingType_H
