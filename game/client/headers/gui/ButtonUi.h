#ifndef TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
#define TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
#include "SDL2pp/SDL2pp.hh"
#include <utility>
using namespace SDL2pp;

class ButtonUi {
private:
    std::pair<int,int> coordinate;
    Texture *texture;
    Rect rectangle;
    Rect area;
public:
    ButtonUi(Texture *texture, Rect dst);
    bool Contains(int x, int y);
    void render(Renderer &render);
};


#endif //TP_FINAL_DUNE_GRUPO_1_BUTTONUI_H
