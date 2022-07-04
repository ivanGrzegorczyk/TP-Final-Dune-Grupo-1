#ifndef TP_FINAL_DUNE_GRUPO_1_TEXTUREMANAGER_H
#define TP_FINAL_DUNE_GRUPO_1_TEXTUREMANAGER_H

#include "common/headers/Constantes.h"
#include <map>
#include "SDL2pp/SDL2pp.hh"

using namespace SDL2pp;

class TextureManager {
private:
    std::map<int, SDL2pp::Texture> ground;
    std::map<int, SDL2pp::Texture> textures;

    SDL2pp::Renderer &render;
public:
    explicit TextureManager(SDL2pp::Renderer &render);
    void loadTile();
    SDL2pp::Texture &getTileOf(int tileType);

    Texture &getTextureOf(int tileType);
};


#endif //TP_FINAL_DUNE_GRUPO_1_TEXTUREMANAGER_H
