#include "../headers/character.h"

void character::render() {
    /*
    if(attackEffect > 0 && attackEffect % 2) {
        normalColor();
        texture->SetColorMod(0, 255, 0);
        attackEffect--;
    }
    else if(hurtEffect > 0) {
        normalColor();
        texture->SetColorMod(255, 0, 0);
        hurtEffect--;
    }*/
    //else 
    if(selected) {
        highlight();
    } else {
        normalColor();
    }
    current.SetX(coord.first * LENGTH_TILE);
    current.SetY(coord.second * LENGTH_TILE);
    current.SetW(24);
    current.SetH(32);

    rnd.Copy(*texture, Rect(0, 0, 13,16), current);
}

void character::update() {
    
}

character::character(SDL2pp::Renderer &renderer, 
    int player, int id, coordenada_t coord, int type) : 
    ClientUnit(player, id, 0, 0, 0, type, coord), 
    rnd(renderer), selected(false),
    texture(new Texture(renderer, Surface(DATA_PATH "/00114a2a.bmp").SetColorKey(true, 0))) {
}

void character::normalColor() {
    texture->SetColorMod(255, 255, 255);
}

void character::highlight() {
    texture->SetColorMod(100, 100, 255);
}
void character::setSelected(bool selected) {
    this->selected = selected;
}
void character::notify(SDL_Event event) {
    int x = event.button.x;
    int y = event.button.y;
    
}

bool character::walkEvent(int x, int y) {
    if(!selected) {
        return false;
    }
    if (!contains(x, y)) {
        selected = false;
        this->normalColor();
        return true;
    } else {
        std::cout << "wont perform walk event"  << std::endl;
    }
    return false;
}

bool character::contains(int x, int y) const {
    return current.Contains(x, y);
}

void character::attack(Damageable* d, int damage) {
    attackEffect = 30; // 30 frames of attacker display
    d->takeDamage(damage);
}

void character::takeDamage(int damage) {
    hurtEffect = 30;
}