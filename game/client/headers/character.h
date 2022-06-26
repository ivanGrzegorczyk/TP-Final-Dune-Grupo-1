#ifndef TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#define TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#include "SDL2pp/SDL2pp.hh"
#include "Request.h"
#include "ClientUnit.h"

using namespace SDL2pp;

class character : public ClientUnit {
private:
    SDL2pp::Texture t;
    Renderer& rnd;
    Rect current;
    bool selected;
    void normalColor();
    void highlight();
public:
    character(SDL2pp::Renderer &renderer, int id, coordenada_t coord, int type);
    Request *walkEvent(int x, int y);
    bool mouseOverUnit(int x, int y) const;
    void render(); //sdl entity
    Request* reactToEvent(int x, int y); //sdl entity
};


#endif //TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
