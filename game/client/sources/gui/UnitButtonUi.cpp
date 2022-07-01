#include "client/headers/gui/UnitButtonUi.h"
#include "client/headers/gui/gui.h"
// TODO inherit with CeldaUi
UnitButtonUi::UnitButtonUi(std::shared_ptr<UnitType> current_unit, Rect dst, GUI* ui) 
: current(current_unit), ui(ui) {
    rectangle = dst;
}

void UnitButtonUi::press() {
    std::cout << "selected unit: " << current->_id << std::endl;
    ui->setUnitToSpawn(current);
}

void UnitButtonUi::render(Renderer &rdr) {
    Point position_texture(0,0);
    Point size_item(70,70);
    Rect src(position_texture, size_item);
    rdr.Copy(current->_texture, src, rectangle);
}

