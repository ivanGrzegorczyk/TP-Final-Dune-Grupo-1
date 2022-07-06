#include "client/headers/TextureManager.h"

TextureManager::TextureManager(SDL2pp::Renderer &render) : render(render){
    loadTile();
}

void TextureManager::loadTile() {
    textures.insert(std::pair(UNIT_LIGHT_INFANTRY,  SDL2pp::Texture
    (render, Surface(DATA_PATH "/00114a2a.bmp").SetColorKey(true, 0))));
    textures.insert(std::pair(UNIT_HEAVY_INFANTRY,  SDL2pp::Texture
    (render, Surface(DATA_PATH "/crate.png").SetColorKey(true, 0))));
    textures.insert(std::pair(VEHICLE_HARVESTER,  SDL2pp::Texture
            (render, Surface(DATA_PATH "/harvester.png").SetColorKey(true, 0))));
    ground.insert(std::pair(TERRAIN_ROCKS,  SDL2pp::Texture (render, DATA_PATH "/rock1.png")));
    ground.insert(std::pair(TERRAIN_SAND,  SDL2pp::Texture (render, DATA_PATH "/sand1.png")));
    ground.insert(std::pair(TERRAIN_CLIFFS,  SDL2pp::Texture (render, DATA_PATH "/cliff1.png")));
    ground.insert(std::pair(TERRAIN_TOPS,  SDL2pp::Texture (render, DATA_PATH "/top1.png")));
    ground.insert(std::pair(TERRAIN_DUNES,  SDL2pp::Texture (render, DATA_PATH "/dune1.png")));
    ground.insert(std::pair(TERRAIN_SPICE_LOW,  SDL2pp::Texture (render, DATA_PATH "/spiceHigh.bmp")));
    ground.insert(std::pair(TERRAIN_SPICE_HIGH,  SDL2pp::Texture (render, DATA_PATH "/spiceLow.bmp")));
}

SDL2pp::Texture &TextureManager::getTileOf(int tileType) {
    return this->ground.at(tileType);
}

SDL2pp::Texture &TextureManager::getTextureOf(int tileType) {
    return this->textures.at(tileType);
}