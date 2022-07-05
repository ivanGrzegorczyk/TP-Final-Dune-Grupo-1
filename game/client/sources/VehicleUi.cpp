#include "client/headers/VehicleUi.h"

#include <utility>

void VehicleUi::render() {
    current.SetX(coord.first * LENGTH_TILE);
    current.SetY(coord.second * LENGTH_TILE);
    current.SetW(50);
    current.SetH(50);

    if(selected) {
        highlight(texture);
    } else {
        normalColor(texture);
    }
    rnd.Copy(texture, Rect(0, 0, 50, 50), current);

}

VehicleUi::VehicleUi(SDL2pp::Renderer &renderer,
                     int player, int id, coordenada_t coord, int type, TextureManager &repo) :
        repository(repo),
        rnd(renderer),
        Entity(id, 30, type, coord),
        selected(false),
        texture(repository.getTextureOf(type)), movable(current, selected){
}

/*
bool VehicleUi::contains(int x, int y) const {
    return false;
}
*/

void VehicleUi::update() {

}

void VehicleUi::takeDamage(int damage) {

}

void VehicleUi::setPosition(coordenada_t newPosition) {
    coord = newPosition;
}

bool VehicleUi::contains(int x, int y) const {
    return current.Contains(x, y);
}
