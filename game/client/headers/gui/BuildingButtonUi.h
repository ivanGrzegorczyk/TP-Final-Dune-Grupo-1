#ifndef TP_FINAL_DUNE_GRUPO_1_BUILDINGBUTTONUI_H
#define TP_FINAL_DUNE_GRUPO_1_BUILDINGBUTTONUI_H
#include "SDL2pp/SDL2pp.hh"
#include "game/client/headers/gui/ButtonUi.h"
#include <utility>
using namespace SDL2pp;
class GUI;
class BuildingButtonUi : public virtual ButtonUi {
private:
    std::pair<int,int> coordinate;
    Texture *texture;
    Rect rectangle;
    GUI* ui;
public:
    BuildingButtonUi(Texture *texture, Rect dst, GUI* ui);
    bool Contains(int x, int y);
    void render(Renderer &render);
    void press();
};


#endif //TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
