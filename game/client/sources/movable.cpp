#include <iostream>
#include "client/headers/movable.h"



bool movable::walkEvent(int x, int y) {
    if(!selected) {
        return false;
    }
    if (!containsCoordinates(x, y)) {
        selected = false;
        //buscar posible id para atacar(coincidir con un id de enemigo)
        return true;
    } else {
        std::cout << "wont perform walk event"  << std::endl;
    }
    return false;
}

movable::movable(Rect &current, bool &selected) :  selected(selected), current(current) {

}

bool movable::containsCoordinates(int x, int y) const {
    return current.Contains(x, y);
}

void movable::normalColor(Texture &texture) {
    texture.SetColorMod(255, 255, 255);
}

void movable::highlight(Texture &texture) {
    texture.SetColorMod(100, 100, 255);
}
void movable::setSelected(bool selected) {
    this->selected = selected;
}