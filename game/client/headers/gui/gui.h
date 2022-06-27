#ifndef TP_FINAL_DUNE_GRUPO_1_GUI_H
#define TP_FINAL_DUNE_GRUPO_1_GUI_H
#include "SDL2pp/SDL2pp.hh"
#include "ButtonUi.h"

#include <utility>
using namespace SDL2pp;
// TODO common parent with cell
class GUI {
private:
    Texture *texture;
    Rect area;
    std::vector<ButtonUi*> buttons;
public:
    GUI(Rect area);
    void render(Renderer &render);
    bool isOverPoint(int x, int y);
    void clickOver(int x, int y);
};


#endif //TP_FINAL_DUNE_GRUPO_1_GUI_H
