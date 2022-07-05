#ifndef TP_FINAL_DUNE_GRUPO_1_VEHICLEUI_H
#define TP_FINAL_DUNE_GRUPO_1_VEHICLEUI_H


#include "common/headers/Entity.h"
#include "SdlEntity.h"
#include "Damageable.h"
#include "TextureManager.h"
#include "movable.h"

using namespace SDL2pp;

class VehicleUi : public Entity, SdlEntity, Damageable, public movable {
private:
    TextureManager &repository;
    Texture &texture;
    bool selected;
    Renderer& rnd;
    Rect current;
public:
    VehicleUi(SDL2pp::Renderer &renderer,
              int player, int id, coordenada_t coord, int type, TextureManager &repo);
    void update() override;
    void render() override;
    bool contains(int x, int y) const override;
    void takeDamage(int damage) override;
    void setPosition(coordenada_t newPosition);
};


#endif //TP_FINAL_DUNE_GRUPO_1_VEHICLEUI_H
