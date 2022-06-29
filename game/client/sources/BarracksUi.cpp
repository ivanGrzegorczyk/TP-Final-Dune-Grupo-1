#include "client/headers/BarracksUi.h"

void BarracksUi::render() {
    location.SetX(coord.first * 8);
    location.SetY(coord.second * 8);
    location.SetW(50);
    location.SetH(50); //TODO: poner w y h acordes
    renderer.Copy(type->texture(), Rect(0, 0, 70, 70), location);
}

void BarracksUi::update() {
        //TODO
}

BarracksUi::BarracksUi(int player, std::shared_ptr<BuildingType> type, Renderer &rdr, coordenada_t coord) : 
          type(type),
          renderer(rdr), 
          coord(coord),
          Building(player, id, BARRACKS_POINTS,
          BUILDING_BARRACKS, coord, BARRACKS_ENERGY, BARRACKS_COST){
            //TODO: ver que pasa con el hp en los edificios
}


