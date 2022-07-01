#ifndef TP_FINAL_DUNE_GRUPO_1_BUILDINGBUTTONUI_H
#define TP_FINAL_DUNE_GRUPO_1_BUILDINGBUTTONUI_H
#include "SDL2pp/SDL2pp.hh"
#include "ButtonUi.h"
#include "client/headers/building_type/BuildingType.h"
#include <memory>

#include <utility>
using namespace SDL2pp;
class GUI;
class BuildingButtonUi : public ButtonUi {
private:
    GUI* ui;
    std::shared_ptr<BuildingType> current_building;
public:
    BuildingButtonUi(std::shared_ptr<BuildingType> current_building, Rect dst, GUI* ui);
    void render(Renderer& render) override;
    void press() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
