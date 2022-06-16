#ifndef TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#define TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#include "SDL2pp/SDL2pp.hh"
#include "../../common/headers/Unit.h"
#include "Request.h"


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
    Character(SDL2pp::Renderer &renderer, int id, coordenada_t coord);
    Request *walkEvent(int x, int y);
    bool mouseOverCharacter(int x, int y) const;
    void render();
    Request* reactToEvent(int x, int y);
    //void update(MapUi *map);
};


#endif //TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
