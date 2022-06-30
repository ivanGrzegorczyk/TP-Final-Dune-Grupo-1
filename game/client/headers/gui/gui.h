#ifndef TP_FINAL_DUNE_GRUPO_1_GUI_H
#define TP_FINAL_DUNE_GRUPO_1_GUI_H
#include "SDL2pp/SDL2pp.hh"
#include "client/headers/building_type/BuildingType.h"
#include "client/headers/building_type/UnitType.h"
#include "game/client/headers/gui/ButtonUi.h"
#include <utility>
#include <memory>
using namespace SDL2pp;
// TODO common parent with cell
class GUI {
private:
    char current_menu = 1;
    Texture *texture;
    Rect area;
    Rect menu1_area;
    Rect menu2_area;
    std::vector<ButtonUi*> buttons;
    std::vector<std::shared_ptr<BuildingType>> building_types;
    std::vector<std::shared_ptr<UnitType>> unit_types;
    std::shared_ptr<BuildingType> selected;
    std::shared_ptr<UnitType> selected_unit;
public:
    GUI(Rect area, 
        std::vector<std::shared_ptr<BuildingType>> building_types,
        std::vector<std::shared_ptr<UnitType>> unit_types) ;
    void render(Renderer &render);
    bool isOverPoint(int x, int y);
    void clickOver(int x, int y);
    void setBuildingToBuild(std::shared_ptr<BuildingType> type);
    void setUnitToSpawn(std::shared_ptr<UnitType> type);
    std::shared_ptr<BuildingType> getBuildingToBuild();
    void drawBuildingButtons(std::vector<std::shared_ptr<BuildingType>> building_types);
    void drawUnitsButtons(std::vector<std::shared_ptr<UnitType>> types);
    void render_menu_buildings(Renderer &rdr);
    void render_menu_units(Renderer &rdr);
    void update();
};


#endif //TP_FINAL_DUNE_GRUPO_1_GUI_H
