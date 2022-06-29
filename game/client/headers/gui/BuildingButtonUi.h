#ifndef TP_FINAL_DUNE_GRUPO_1_BUILDINGBUTTONUI_H
#define TP_FINAL_DUNE_GRUPO_1_BUILDINGBUTTONUI_H
#include "SDL2pp/SDL2pp.hh"
#include "ButtonUi.h"

#include <utility>
using namespace SDL2pp;
class GUI;
class BuildingButtonUi : public ButtonUi {
private:
    Texture &texture;
    GUI* ui;
public:
    BuildingButtonUi(Texture &texture, Rect dst, GUI* ui);
    void render(Renderer& render) override;
    void press() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
