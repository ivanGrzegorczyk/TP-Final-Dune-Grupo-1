#ifndef TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
#define TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
#include "SDL2pp/SDL2pp.hh"
#include <utility>
using namespace SDL2pp;

class ButtonUi {
protected:
    Rect rectangle;
public:
    ButtonUi();
    virtual bool Contains(int x, int y);
    virtual void render(Renderer &render);
    virtual void press() = 0;
};


#endif //TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
