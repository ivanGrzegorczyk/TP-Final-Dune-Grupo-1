#ifndef TP_FINAL_DUNE_GRUPO_1_CELDAUI_H
#define TP_FINAL_DUNE_GRUPO_1_CELDAUI_H
#include "SDL2pp/SDL2pp.hh"
#include <utility>
using namespace SDL2pp;

class CeldaUi {
private:
    std::pair<int,int> coordinate;
    Texture &texture;
    Rect rectangle;
    Rect area;
public:
    //CeldaUi();
    CeldaUi(Texture &texture, std::pair<int, int> coord, Rect dst, Rect area);
    void render(Renderer &render);
};


#endif //TP_FINAL_DUNE_GRUPO_1_CELDAUI_H
