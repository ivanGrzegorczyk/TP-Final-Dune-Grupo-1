#ifndef TP_FINAL_DUNE_GRUPO_1_GUI_H
#define TP_FINAL_DUNE_GRUPO_1_GUI_H
#include "SDL2pp/SDL2pp.hh"
#include "client/headers/building_type/BuildingType.h"
#include "game/client/headers/gui/ButtonUi.h"
#include <utility>
#include <memory>
using namespace SDL2pp;
// TODO common parent with cell
class GUI {
private:
    Texture *texture;
    Rect area;
    Rect menu1_area;
    Rect menu2_area;
    std::vector<ButtonUi*> buttons;
    std::shared_ptr<BuildingType> selected;
public:
    GUI(Rect area, std::vector<std::shared_ptr<BuildingType>> building_types);
    void render(Renderer &render);
    bool isOverPoint(int x, int y);
    void clickOver(int x, int y);
    void setBuildingToBuild(std::shared_ptr<BuildingType> type);
    std::shared_ptr<BuildingType> getBuildingToBuild();
};


#endif //TP_FINAL_DUNE_GRUPO_1_GUI_H
