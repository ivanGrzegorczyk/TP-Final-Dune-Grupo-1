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
}

void character::normalColor() {
    texture->SetColorMod(255, 255, 0);
}

void character::highlight() {
    texture->SetColorMod(255, 0, 0);
}
void character::setSelected(bool selected) {
    this->selected = selected;
    if (selected) {
        this->highlight();
    } else {
        this->normalColor();
    }
}
void character::notify(SDL_Event event) {
    int x = event.button.x;
    int y = event.button.y;
    
}

Request *character::walkEvent(int x, int y) {
    std::cout << "getting walk event!" << std::endl;
    if(!selected) {
        std::cout << "not selected lmfao!" << std::endl;
        return nullptr;
    }
    if (!contains(x, y)) {
        selected = false;
        this->normalColor();
        coordenada_t coord({x, y});
        Request *query = new MoveQuery(id, std::move(coord));
        return query;
    } else {
        std::cout << "wont perform walk event"  << std::endl;
    }
    return nullptr;
}

bool character::contains(int x, int y) const {
    return current.Contains(x, y);
}
