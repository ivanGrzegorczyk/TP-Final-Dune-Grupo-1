#ifndef TP_FINAL_DUNE_GRUPO_1_GUI_H
#define TP_FINAL_DUNE_GRUPO_1_GUI_H
#include "SDL2pp/SDL2pp.hh"
#include <utility>
using namespace SDL2pp;
// TODO common parent with cell
class GUI {
private:
    Texture *texture;
    Rect area;
public:
    GUI(Rect area);
    void render(Renderer &render);
};


#endif //TP_FINAL_DUNE_GRUPO_1_GUI_H
