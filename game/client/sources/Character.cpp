#include "../headers/Character.h"

std::pair<int, int> Character::getCoordinates() {
    return std::make_pair(pos_X, pos_Y);
}

void Character::render() {
    //current.SetX(pos)
    current.SetX(pos_X * 8);
    current.SetY(pos_Y * 8);
    current.SetW(24);
    current.SetH(32);
    rnd.Copy(t, Rect(0, 0, 13,16), current);
}

void Character::update() {
    int x;
    int y;
    if(pos < path.size()) {
        std::pair<int, int> cell = path[pos];
        x = cell.first; /
        y = cell.second;
        //if (isMoving) {
            current.SetX(x);
            current.SetY(y);
            pos_X = x;
            pos_Y = y;
            pos++;
        //}
    } else {
        path.clear();
        pos = 0;
    }
}

Character::Character(SDL2pp::Renderer &renderer) : rnd(renderer), selected(false), isMoving(false),pos(0) ,desY(0), desX(0),pos_X(20),pos_Y(5),
                                                    t(Texture(renderer, Surface(DATA_PATH "/00114a2a.bmp")
                                                    .SetColorKey(true, 0))) {
}

void Character::move(std::vector<coordenada_t> &pathDes) { // recibo coordenadas del servidor
    /*coordenada_t currentPos {pos_X, pos_Y};
    coordenada_t destPos {desX, desY};*/
    //protocol->caminar(currentPos, destPos);
   /* path.push_back(std::make_pair(0, 1));
    path.push_back(std::make_pair(0, 2));
    path.push_back(std::make_pair(0, 3));
    path.push_back(std::make_pair(0, 4));
    path.push_back(std::make_pair(0, 5));
    path.push_back(std::make_pair(0, 6));
    path.push_back(std::make_pair(0, 7));
    path.push_back(std::make_pair(1, 7));*/
    //path.push_back(std::make_pair(x, y));

}
void Character::changeColor() {
    if(selected) {
        t.SetColorMod(255, 0, 0);
    } else {
        t.SetColorMod(255, 255, 0);
    }
}

void Character::mouseEvent(int x, int y) {
    desX = x;
    desY = y;
}

bool Character::reactToEvent(int x, int y, std::pair<coordenada_t, coordenada_t> &ubication) { //cambiar nombre
    desX = x;
    desY = y;
    bool change;
    if (!current.Contains(desX, desY) && selected) {
        ubication.first.first = pos_X;
        ubication.first.second = pos_Y;
        ubication.second.first = desX;
        ubication.second.second = desY;
        return true;
    }
    if (current.Contains(desX, desY) && !selected) {
        change = true;
    }
    if (current.Contains(desX, desY) && selected) {
        change = false;
    }
    selected = change;
    changeColor();
    return false;
}
bool Character::isSelected() const {
    return selected;
}
