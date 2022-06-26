#include "game/client/headers/gui/ButtonUi.h"
ButtonUi::ButtonUi() {}
void ButtonUi::render(Renderer &rdr) {
    rdr.DrawRect(rectangle);
}

bool ButtonUi::Contains(int x, int y) {
    return rectangle.Contains(x,y);
}