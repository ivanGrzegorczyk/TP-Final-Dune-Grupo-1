#include "../headers/Character.h"
#include "../headers/MoveQuery.h"

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
        x = cell.first;
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
/*void Character::changeColor() {
    if(selected) {
        t.SetColorMod(255, 0, 0);
    } else {
        t.SetColorMod(255, 255, 0);
    }
}*/

void Character::normalColor() {
    t.SetColorMod(255, 0, 0);
}

void Character::highlight() {
    t.SetColorMod(255, 255, 0);
}

Request* Character::reactToEvent(int x, int y) {
    if(mouseOverCharacter(x, y) && selected) {
        return walkEvent(x, y);
    } else if(mouseOverCharacter(x, y) && !selected) {
        selected = true;
        this->highlight();
    } else {
        selected = false;
        this->normalColor();
    }
    return nullptr;
}

Request *Character::walkEvent(int x, int y) {
    selected = false;
    coordenada_t coord({x, y});
    Request* query = new MoveQuery(id, std::move(coord));
    return query;
}

bool Character::mouseOverCharacter(int x, int y) const {
    return current.Contains(x, y);
}

bool Character::isSelected() const {
    return this->selected;
}
