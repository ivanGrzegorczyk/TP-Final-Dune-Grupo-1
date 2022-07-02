#ifndef TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#define TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#include "SDL2pp/SDL2pp.hh"
#include "Request.h"
#include "ClientUnit.h"
#include <memory>
using namespace SDL2pp;

class character : public ClientUnit {
private:
    std::shared_ptr<Texture> texture;
    Renderer& rnd;
    Rect current;
    bool selected;
    void normalColor();
    void highlight();
public:
    character(SDL2pp::Renderer &renderer, int player, int id, coordenada_t coord, int type);
    Request *walkEvent(int x, int y);
    void notify(SDL_Event event);
    void render();
    void update();
    bool contains(int x, int y) const;
    void setSelected(bool was_selected); // TODO inefficient rendering over and over
};


#endif //TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
