#include "client/headers/gui/BuildingButtonUi.h"

// TODO inherit with CeldaUi
BuildingButtonUi::BuildingButtonUi(std::shared_ptr<BuildingType> current_building, Rect dst, GUI* ui) 
: current_building(current_building), ui(ui) {
    rectangle = dst;
}

void BuildingButtonUi::press() {
    std::cout << "picking building" << std::endl;
}

void BuildingButtonUi::render(Renderer &rdr) {
    Point position_texture(0,0);
    Point size_item(70,70);
    Rect src(position_texture, size_item);
    rdr.Copy(current_building->texture(), src, rectangle);
}

