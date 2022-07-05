#include "client/headers/VehicleUi.h"

#include <utility>

void VehicleUi::render() {
    current.SetX(coord.first * LENGTH_TILE);
    current.SetY(coord.second * LENGTH_TILE);
    current.SetW(50);
    current.SetH(50);
    rnd.Copy(texture, Rect(0, 0, 50, 50), current);

}

VehicleUi::VehicleUi(SDL2pp::Renderer &renderer,
                     int player, int id, coordenada_t coord, int type, TextureManager &repo) :
        repository(repo),
        rnd(renderer),
        coord(std::move(coord)),
        texture(repository.getTextureOf(type)) {
}

bool VehicleUi::contains(int x, int y) const {
    return false;
}

void VehicleUi::update() {

}

void VehicleUi::takeDamage(int damage) {

}
