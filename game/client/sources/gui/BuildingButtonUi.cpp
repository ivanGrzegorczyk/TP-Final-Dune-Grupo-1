#include "game/client/headers/gui/BuildingButtonUi.h"
#include "game/client/headers/MapUi.h"

// TODO inherit with CeldaUi
BuildingButtonUi::BuildingButtonUi(Texture *texture, Rect dst, GUI* ui) 
: texture(texture), rectangle(dst), ui(ui), ButtonUi(texture, dst) {

}

void BuildingButtonUi::render(Renderer &rdr) {
    rdr.DrawRect(rectangle);
}

bool BuildingButtonUi::Contains(int x, int y) {
    return rectangle.Contains(x,y);
}

void BuildingButtonUi::press() {
    
}