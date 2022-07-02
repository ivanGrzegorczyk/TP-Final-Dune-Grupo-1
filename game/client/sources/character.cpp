#include "../headers/character.h"
#include "../headers/MoveQuery.h"

void character::render() {
    current.SetX(coord.first * 8);
    current.SetY(coord.second * 8);
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
        std::cout << "creating new unit: " << player << std::endl;
}

void character::normalColor() {
    texture->SetColorMod(255, 255, 0);
}

void character::highlight() {
    texture->SetColorMod(255, 0, 0);
}

void character::notify(SDL_Event event) {
    int x = event.button.x;
    int y = event.button.y;
    if (mouseOverUnit(x, y) && !selected) {
        selected = true;
        this->highlight();
    } else {
        selected = false;
        this->normalColor();
    }
}

Request *character::walkEvent(int x, int y) {
    if (!mouseOverUnit(x, y) && selected) {
        selected = false;
        this->normalColor();
        coordenada_t coord({x, y});
        Request *query = new MoveQuery(id, std::move(coord));
        return query;
    }
    return nullptr;
}

bool character::mouseOverUnit(int x, int y) const {
    return current.Contains(x, y);
}
