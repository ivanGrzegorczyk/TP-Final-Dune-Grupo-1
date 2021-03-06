#ifndef TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#define TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#include "SDL2pp/SDL2pp.hh"
#include "ClientUnit.h"
#include "client/headers/AttackRequest.h"
#include "TextureManager.h"
#include "movable.h"
#include <memory>
using namespace SDL2pp;

class character : public ClientUnit, public movable {
private:
    //std::shared_ptr<Texture> texture;
    TextureManager &repository;
    Texture &texture;
    Renderer& rnd;
    Rect current;
    bool selected;
    int attackEffect = 0; // simple frame counter for effect
    int hurtEffect = 0; // simple frame counter for effect
 /*   void normalColor();
    void highlight();*/
public:
    character(SDL2pp::Renderer &renderer, int player, int id, coordenada_t coord, int type, TextureManager &repo);
    //bool walkEvent(int x, int y);
    bool attackEvent(int id);
    void notify(SDL_Event event);
    void render();
    void update();
    bool contains(int x, int y) const override;
    //void setSelected(bool was_selected); // TODO inefficient rendering over and over
    void takeDamage(int damage);
    void attack(Damageable* d, int damage);
};


#endif //TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
