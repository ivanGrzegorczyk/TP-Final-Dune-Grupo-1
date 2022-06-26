#include "game/client/headers/gui/ButtonUi.h"
// TODO inherit with CeldaUi
ButtonUi::ButtonUi(Texture *texture, Rect dst) : texture(texture), rectangle(dst){

}

void ButtonUi::render(Renderer &rdr) {
    rdr.DrawRect(rectangle);
}

bool ButtonUi::Contains(int x, int y) {
    return rectangle.Contains(x,y);
}