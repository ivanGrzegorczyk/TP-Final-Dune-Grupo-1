

#include "client/headers/gui/gui.h"

GUI::GUI(Rect area) : area(area){
}

bool GUI::isOverPoint(int x, int y) {
    return area.Contains(x,y);
}

void GUI::clickOver(int x, int y) {
    std::cout << "clicked on the menu" << std::endl;
}

void GUI::render(Renderer &rdr) {
    int menu_rows = 4;
    int menu_columns = 2;
    int width_item = int(area.GetW() / menu_columns);
    int height_item = int(area.GetH() / menu_rows);
    //std::cout << width_item << "," << height_item << std::endl;
    Point size_item(width_item, height_item);
    Point origin = area.GetTopLeft();
    for(int i = 0; i < menu_rows; i++) {
        for(int j = 0; j < menu_columns; j++) {
            Point item_origin = origin + Point(width_item, 0) * j + Point(0, height_item) * i;
            Rect item(item_origin, size_item);
            rdr.DrawRect(item);
        }
    }
    rdr.SetDrawColor(255,0,0,255);
    std::vector<std::string> buildings = {"Bil1", "Bil2", "bil3"};
    rdr.DrawRect(area);
}
