#ifndef TP_FINAL_DUNE_GRUPO_1_UnitBUTTONUI_H
#define TP_FINAL_DUNE_GRUPO_1_UnitBUTTONUI_H
#include "SDL2pp/SDL2pp.hh"
#include "ButtonUi.h"
#include "client/headers/building_type/UnitType.h"
#include <memory>
#include <utility>
using namespace SDL2pp;
class GUI;
class UnitButtonUi : public ButtonUi {
private:
    GUI* ui;
    std::shared_ptr<UnitType> current;
public:
    UnitButtonUi(std::shared_ptr<UnitType> current_unit, Rect dst, GUI* ui);
    void render(Renderer& render) override;
    void press() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
