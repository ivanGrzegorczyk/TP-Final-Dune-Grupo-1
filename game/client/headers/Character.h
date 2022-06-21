#ifndef TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#define TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#include "SDL2pp/SDL2pp.hh"
#include "Request.h"
#include "../../common/headers/Unit.h"

using namespace SDL2pp;

class Character : public Unit {
private:
    SDL2pp::Texture t;
    Renderer& rnd;
    Rect current;
    bool selected;
    void normalColor();
    void highlight();
public:
    Character(SDL2pp::Renderer &renderer, int id, coordenada_t coord, int type);
    Request *walkEvent(int x, int y);
    bool mouseOverCharacter(int x, int y) const;
    void render();
    Request* reactToEvent(int x, int y);
};


#endif //TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
