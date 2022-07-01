#include <fstream>
#include <vector>
#include <string>
#include "client/headers/gui/gui.h"
#include "client/headers/gui/BuildingButtonUi.h"
#include "client/headers/gui/UnitButtonUi.h"

GUI::GUI(Rect area,
         std::vector<std::shared_ptr<BuildingType>> building_types,
         std::vector<std::shared_ptr<UnitType>> unit_types) :
        area(area),
        building_types(building_types),
        unit_types(unit_types) {
    float PORTION_1 = 0.9;
    float PORTION_2 = 0.1;

    // main menu with 8 slots
    menu1_area = area;
    menu1_area.SetH((int)(area.GetH() * PORTION_1));
    // menu number two
    menu2_area = Rect(menu1_area.GetBottomLeft(),area.GetSize());
    menu2_area.SetH((int)(area.GetH() * PORTION_2));
    update();
}

void GUI::update() {
    if(current_menu == 1) {
        drawBuildingButtons(building_types);
    } else if(current_menu == 2) {
        drawUnitsButtons(unit_types);
    }
}

bool GUI::isOverPoint(int x, int y) {
    return area.Contains(x,y);
}

void GUI::clickOver(int x, int y) {
    if(menu2_area.Contains(x,y)) {
        current_menu = (current_menu == 1) ? 2 : 1;
    } else {
        for(auto it = buttons.begin(); it != buttons.end(); ++it) {
            if((*it)->Contains(x,y)) {
                (*it)->press();
            }
        }
    }
    update();
}

// todo cache some of this logic as as object state
void GUI::render(Renderer &rdr) {
    rdr.DrawRect(menu1_area);
    rdr.DrawRect(menu2_area);
    render_menu_buildings(rdr);
    rdr.SetDrawColor(255,0,0,255);
    rdr.DrawRect(area);
}

void GUI::render_menu_buildings(Renderer &rdr) {
    for(auto it = buttons.begin(); it != buttons.end(); ++it) {
        (*it)->render(rdr);
    }
}

void GUI::render_menu_units(Renderer &rdr) {
    for(auto it = buttons.begin(); it != buttons.end(); ++it) {
        (*it)->render(rdr);
    }
}

void GUI::setBuildingToBuild(std::shared_ptr<BuildingType> type) {
    selected = type;
}

void GUI::setUnitToSpawn(std::shared_ptr<UnitType> type) {
    selected_unit = type;
}

std::shared_ptr<BuildingType> GUI::getBuildingToBuild() {
    return selected;
}

void GUI::drawBuildingButtons(std::vector<std::shared_ptr<BuildingType>> building_types) {
    buttons.clear();
    // main menu buttons
    int menu_rows = 4;
    int menu_columns = 2;
    int width_item = int(menu1_area.GetW() / menu_columns);
    int height_item = int(menu1_area.GetH() / menu_rows);
    Point size_item(width_item, height_item);
    Point origin = menu1_area.GetTopLeft();

    // get all buildings that are drawable by the menu
    int construction_center_code = BUILDING_CONSTRUCTION_CENTER;
    auto it = building_types.begin();
    auto _end = building_types.end();
    auto menu_end = std::remove_if(it,_end,
                                   [construction_center_code](std::shared_ptr<BuildingType> b){
                                       return b->code() == construction_center_code;
                                   });
    // TODO: Create 'SDLBuilding class tht combines sdl entity with building properties

    // by default, we place the first building available
    if(it != menu_end) selected = *it;
    //TODO more legantly iterate over matrix
    for(int i = 0; i < menu_rows; i++) {
        for(int j = 0; j < menu_columns; j++) {
            if(it == menu_end) break;
            Point item_origin =
                    origin
                    + Point(width_item, 0) * j
                    + Point(0, height_item) * i;
            Rect item(item_origin, size_item);
            std::cout << item.GetH() << item.GetW() << item.GetX() << item.GetY();
            BuildingButtonUi* b = new BuildingButtonUi(*it, item, this);
            buttons.push_back(b);
            ++it;
        }
    }
}


void GUI::drawUnitsButtons(std::vector<std::shared_ptr<UnitType>> units) {
    buttons.clear();
    // main menu buttons
    int menu_rows = 4;
    int menu_columns = 2;
    int width_item = int(menu1_area.GetW() / menu_columns);
    int height_item = int(menu1_area.GetH() / menu_rows);
    Point size_item(width_item, height_item);
    Point origin = menu1_area.GetTopLeft();

    // get all unitsthat are drawable by the menu
    int construction_center_code = BUILDING_CONSTRUCTION_CENTER;
    auto it = units.begin();
    auto _end = units.end();
    // TODO: Create 'SDLBuilding class tht combines sdl entity with building properties

    // by default, we place the first building available
    if(it != _end) selected_unit = *it;
    //TODO more legantly iterate over matrix
    for(int i = 0; i < menu_rows; i++) {
        for(int j = 0; j < menu_columns; j++) {
            if(it == _end) break;
            Point item_origin =
                    origin
                    + Point(width_item, 0) * j
                    + Point(0, height_item) * i;
            Rect item(item_origin, size_item);
            std::cout << item.GetH() << item.GetW() << item.GetX() << item.GetY();
            UnitButtonUi* b = new UnitButtonUi(*it, item, this);
            buttons.push_back(b);
            ++it;
        }
    }
}
