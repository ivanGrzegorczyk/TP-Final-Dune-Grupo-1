#include "../headers/Character.h"
#include "../headers/MoveQuery.h"
#include "../headers/MapUi.h"

void Character::render() {
    current.SetX(coord.first * 8);
    current.SetY(coord.second * 8);
    current.SetW(24);
    current.SetH(32);

    rnd.Copy(t, Rect(0, 0, 13,16), current);
}

Character::Character(SDL2pp::Renderer &renderer, int id, coordenada_t coord, int type) : Unit(id, 0, 0, 0, type, coord), rnd(renderer), selected(false),
                                                                               t(Texture(renderer, Surface(DATA_PATH "/00114a2a.bmp")
                                                    .SetColorKey(true, 0))) {
}

void Character::normalColor() {
    t.SetColorMod(255, 255, 0);
}

void Character::highlight() {
    t.SetColorMod(255, 0, 0);
}

Request* Character::reactToEvent(int x, int y) {
    if (mouseOverCharacter(x, y) && !selected) {
        selected = true;
        this->highlight();
    } else {
        selected = false;
        this->normalColor();
    }
    return nullptr;
}

Request *Character::walkEvent(int x, int y) {
    if (!mouseOverCharacter(x, y) && selected) {
        selected = false;
        this->normalColor();
        coordenada_t coord({x / 8, y / 8});
        Request *query = new MoveQuery(id, std::move(coord));
        return query;
    }
    return nullptr;
}

bool Character::mouseOverCharacter(int x, int y) const {
    return current.Contains(x, y);
}
