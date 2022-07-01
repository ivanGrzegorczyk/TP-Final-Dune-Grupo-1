#include "client/headers/BuildingUi.h"

void BuildingUi::render() {
    renderer.Copy(type->texture(), Rect(0, 0, 70, 70), location);
}

void BuildingUi::update() {
    //TODO
}
// TODO improve encapsulation
BuildingUi::BuildingUi(
        int player,
        int buildingId,
        std::shared_ptr<BuildingType> type,
        Renderer &rdr,
        coordenada_t coord,
        Point size = Point(50,50),
        Point map_center = Point(0,0))
        : type(type),
          renderer(rdr),
          coord(coord) {
    std::cout << "creating map building" <<std::endl;
    Point _pos(coord.first, coord.second);
    _pos = _pos * 8 + map_center;
    Rect _location(_pos, size);
    location = _location;
}


