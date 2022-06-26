#ifndef TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H
#define TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H
#include "SDL2pp/SDL2pp.hh"
#include "Request.h"
#include "common/headers/Entity.h"

using namespace SDL2pp;

class ClientUnit : public Entity {
private:
    SDL2pp::Texture t;
    Renderer& rnd;
    Rect current;
    bool selected;
    void normalColor();
    void highlight();
public:
    ClientUnit(SDL2pp::Renderer &renderer, int id, coordenada_t coord, int type);
    Request *walkEvent(int x, int y);
    bool mouseOverUnit(int x, int y) const;
    void render(); //sdl entity
    Request* reactToEvent(int x, int y); //sdl entity
};


#endif //TP_FINAL_DUNE_GRUPO_1_CLIENTUNIT_H
