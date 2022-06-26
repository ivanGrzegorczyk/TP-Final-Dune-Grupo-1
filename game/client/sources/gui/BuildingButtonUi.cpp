#include "game/client/headers/gui/BuildingButtonUi.h"
#include "game/client/headers/MapUi.h"

// TODO inherit with CeldaUi
BuildingButtonUi::BuildingButtonUi(Texture *texture, Rect dst, GUI* ui) 
: texture(texture), ui(ui) {
    rectangle = dst;
}

void BuildingButtonUi::press() {
    std::cout << "picking building" << std::endl;
}