#ifndef TP_FINAL_DUNE_GRUPO_1_BARRACKSUI_H
#define TP_FINAL_DUNE_GRUPO_1_BARRACKSUI_H

#include "SDL2pp/SDL2pp.hh"
#include "common/headers/Building.h"

using namespace SDL2pp;
class BarracksUi : public Building {
private:
    Texture texture;
    Rect location;
    Renderer &renderer;
public:
    explicit BarracksUi(coordenada_t coord, int id ,Renderer &rdr);
    void render();
    void update();
};


#endif //TP_FINAL_DUNE_GRUPO_1_BARRACKSUI_H
