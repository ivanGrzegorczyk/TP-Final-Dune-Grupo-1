#include "client/headers/BarracksUi.h"

void BarracksUi::render() {
    location.SetX(coord.first * 8);
    location.SetY(coord.second * 8);
    location.SetW(50);
    location.SetH(50); //TODO: poner w y h acordes
    renderer.Copy(texture, Rect(0, 0, 30, 30), location);
}

void BarracksUi::update() {
        //TODO
}

BarracksUi::BarracksUi(int player, coordenada_t coord, int id ,Renderer &rdr) : texture(Texture(rdr,
          Surface(DATA_PATH "/barracks.png"))),
          renderer(rdr), Building(player, id, BARRACKS_POINTS,
          BUILDING_BARRACKS, coord, BARRACKS_ENERGY, BARRACKS_COST){
            //TODO: ver que pasa con el hp en los edificios
}


