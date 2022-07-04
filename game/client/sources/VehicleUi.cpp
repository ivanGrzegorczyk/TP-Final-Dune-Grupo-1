#include "client/headers/VehicleUi.h"

void VehicleUi::render() {
    current.SetX(coord.first * 8);
    current.SetY(coord.second * 8);
    current.SetW(50);
    current.SetH(50);
    rnd.Copy(texture, Rect(0, 0, 50, 50), current);

}

VehicleUi::VehicleUi(SDL2pp::Renderer &renderer,
                     int player, int id, coordenada_t coord, int type, TextureManager &repo) :
        repository(repo),
        rnd(renderer),
        texture(repository.getTextureOf(type)) {
}

bool VehicleUi::contains(int x, int y) const {
    return false;
}

void VehicleUi::update() {

}

void VehicleUi::takeDamage(int damage) {

}
