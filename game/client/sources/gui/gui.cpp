#include "game/client/headers/gui/gui.h"
#include <vector>
#include <string>
GUI::GUI(Rect area) : area(area){
    int menu_rows = 4;
    int menu_columns = 2;
    int width_item = int(area.GetW() / menu_columns);
    int height_item = int(area.GetH() / menu_rows);
    std::cout << width_item << "," << height_item << std::endl;
    Point size_item(width_item, height_item);
    Point origin = area.GetTopLeft();
    std::vector<std::string> buildings = {"Bil1", "Bil2", "bil3", "bil4", "bil5"};
    auto it = buildings.begin();
    //TODO more legantly iterate over matrix
    for(int i = 0; i < menu_rows; i++) {
        for(int j = 0; j < menu_columns; j++) {
            if(it == buildings.end()) break;
            // TODO button object
            Point item_origin = origin + Point(width_item, 0) * j + Point(0, height_item) * i;
            Rect item(item_origin, size_item);
            buttons.push_back(item);
            std::cout << *it;
            ++it;
            
        }
    }
}

bool GUI::isOverPoint(int x, int y) {
    return area.Contains(x,y);
}

void GUI::clickOver(int x, int y) {
    std::cout << "clicked on the menu" << std::endl;
}

// todo cache some of this logic as as object state
void GUI::render(Renderer &rdr) {
    rdr.SetDrawColor(255,0,0,255);
    for(auto it = buttons.begin(); it != buttons.end(); ++it) {
        rdr.DrawRect(*it);
    }
    rdr.DrawRect(area);
}
