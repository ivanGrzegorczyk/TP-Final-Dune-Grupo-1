#include "game/client/headers/gui/gui.h"

GUI::GUI(Rect area) : area(area){}

void GUI::render(Renderer &rdr) {
    rdr.DrawRect(area);
}
