#ifndef TP_FINAL_DUNE_GRUPO_1_TERRAINREPOSITORY_H
#define TP_FINAL_DUNE_GRUPO_1_TERRAINREPOSITORY_H

#include "common/headers/Constantes.h"
#include <map>
#include "SDL2pp/Texture.hh"

class TerrainRepository {
private:
    std::map<int, SDL2pp::Texture> ground;
    SDL2pp::Renderer &render;
public:
    explicit TerrainRepository(SDL2pp::Renderer &render);
    void loadTile();
    SDL2pp::Texture &getTileOf(int tileType);
};


#endif //TP_FINAL_DUNE_GRUPO_1_TERRAINREPOSITORY_H
