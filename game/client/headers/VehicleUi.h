#ifndef TP_FINAL_DUNE_GRUPO_1_VEHICLEUI_H
#define TP_FINAL_DUNE_GRUPO_1_VEHICLEUI_H


#include "common/headers/Entity.h"
#include "SdlEntity.h"
#include "Damageable.h"
#include "TextureManager.h"

using namespace SDL2pp;

class VehicleUi : public Entity, SdlEntity, Damageable {
private:
    TextureManager &repository;
    Texture &texture;
    Renderer& rnd;
    Rect current;
public:
    VehicleUi(SDL2pp::Renderer &renderer,
              int player, int id, coordenada_t coord, int type, TextureManager &repo);
    void update() override;
    void render() override;
    bool contains(int x, int y) const override;
    void takeDamage(int damage) override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_VEHICLEUI_H
