#include "client/headers/TerrainRepository.h"

TerrainRepository::TerrainRepository(SDL2pp::Renderer &render) : render(render){
    loadTile();
}

void TerrainRepository::loadTile() {
    ground.insert(std::pair(TERRAIN_ROCKS,  SDL2pp::Texture (render, DATA_PATH "/rock1.png")));
    ground.insert(std::pair(TERRAIN_SAND,  SDL2pp::Texture (render, DATA_PATH "/sand1.png")));
    ground.insert(std::pair(TERRAIN_CLIFFS,  SDL2pp::Texture (render, DATA_PATH "/cliff1.png")));
    ground.insert(std::pair(TERRAIN_TOPS,  SDL2pp::Texture (render, DATA_PATH "/top1.png")));
    ground.insert(std::pair(TERRAIN_DUNES,  SDL2pp::Texture (render, DATA_PATH "/dune1.png")));
}

SDL2pp::Texture &TerrainRepository::getTileOf(int tileType) {
    return this->ground.at(tileType);
}
