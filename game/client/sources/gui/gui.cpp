#include "game/client/headers/gui/gui.h"
#include "game/client/headers/gui/ButtonUi.h"
#include "game/client/headers/gui/BuildingButtonUi.h"
#include <fstream>
#include <vector>
#include <string>
#include "client/headers/gui/gui.h"
#include "client/headers/gui/BuildingButtonUi.h"

GUI::GUI(Rect area, std::vector<BuildingType>& building_types) : area(area){
    int menu_rows = 4;
    int menu_columns = 2;
    int width_item = int(area.GetW() / menu_columns);
    int height_item = int(area.GetH() / menu_rows);
    //std::cout << width_item << "," << height_item << std::endl;
    Point size_item(width_item, height_item);
    Point origin = area.GetTopLeft();
    // TODO: Create 'SDLBuilding class tht combines sdl entity with building properties
    auto it = building_types.begin();
    //TODO more legantly iterate over matrix
    for(int i = 0; i < menu_rows; i++) {
        for(int j = 0; j < menu_columns; j++) {
            if(it == building_types.end()) break;
            std::cout << (*it).type << std::endl;
            Point item_origin = origin + Point(width_item, 0) * j + Point(0, height_item) * i;
            Rect item(item_origin, size_item);
            BuildingButtonUi* b = new BuildingButtonUi(nullptr, item, this);
            buttons.push_back(b);
            ++it;
            
        }
    }
}

bool GUI::isOverPoint(int x, int y) {
    return area.Contains(x,y);
}

void GUI::clickOver(int x, int y) {
    for(auto it = buttons.begin(); it != buttons.end(); ++it) {
        if((*it)->Contains(x,y)) {
            (*it)->press();
        }
    }
}

// todo cache some of this logic as as object state
void GUI::render(Renderer &rdr) {
    rdr.SetDrawColor(255,0,0,255);
    for(auto it = buttons.begin(); it != buttons.end(); ++it) {
        (*it)->render(rdr);
    }
    rdr.DrawRect(area);
}
