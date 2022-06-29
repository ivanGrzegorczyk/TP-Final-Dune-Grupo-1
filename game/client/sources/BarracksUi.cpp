#include "client/headers/BarracksUi.h"

void BarracksUi::render() {
    
}

void BarracksUi::update() {
    //TODO
}

BarracksUi::BarracksUi(
        int player, 
        std::shared_ptr<BuildingType> type, 
        Renderer &rdr, 
        coordenada_t coord, 
        Point map_center = Point(0,0)) 
        : type(type),
        renderer(rdr), 
        coord(coord) {
    Rect location;
    location.SetX(coord.first * 8 + map_center.GetX());
    location.SetY(coord.second * 8 + map_center.GetY());
    location.SetW(50);
    location.SetH(50); //TODO: poner w y h acordes
    renderer.Copy(type->texture(), Rect(0, 0, 70, 70), location);
    //TODO: ver que pasa con el hp en los edificios
}


