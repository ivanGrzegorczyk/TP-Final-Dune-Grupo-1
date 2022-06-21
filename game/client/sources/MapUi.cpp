#include "../headers/MapUi.h"

MapUi::MapUi(Renderer &renderer) : rdr(renderer), ground (renderer, Surface(DATA_PATH "/d2k_BLOXBASE.bmp")){
    dst.SetX(0) = dst.SetY(0);
    dst.SetW(LENGTH_TILE) = dst.SetH(LENGTH_TILE);
}

void MapUi::update(Response *response) {
    response->update(this->units, rdr);
}

void MapUi::receiveMap(Protocol &protocol) {
    this->terrain = protocol.receiveTerrain();
}

void MapUi::draw() {
    int k = 0;
    for(int i = 0; i < this->terrain.first.first; i++) {
        for (int j = 0; j < this->terrain.first.second; j++) {
            coordenada_t coord(i, j);
            dst.SetX(j * LENGTH_TILE);
            dst.SetY(i * LENGTH_TILE);
            uint8_t type = this->terrain.second.at(k);
            if(type == TERRAIN_ROCKS) {
                this->addRocks(coord, dst);
            }else {
                this->addSand(coord, dst);
            }
            k++;
        }
   }
}

void MapUi::render() {
    rdr.Clear();
    Rect r(100, 220, 8, 8);
    rdr.Copy(ground, r, Rect(1500 , 1500 , 8, 8));
    for(auto& tile : map) {
        tile.render(rdr);
    }
    for(auto const& [playerId, unitsMap] : units) {
       for(auto const& [unitId, unit]: unitsMap) {
           unit->render();
       }
    }
    rdr.Present();
}

Request* MapUi::mouseEvent(int x, int y, int playerId) {
    for (auto const& [unitId, unit] : units[playerId]) {
        unit->reactToEvent(x, y);
    }
    return nullptr;
}

Request* MapUi::moveCharacter(int x, int y, int playerId) {
    Request *request;
    for (auto const& [unitId, unit] : units[playerId]) {
        request = unit->walkEvent(x, y);
        if (request != nullptr)
        std::cout << "Enviando..." << std::endl;
            return request;
    }
    return nullptr;
}

void MapUi::addRocks(coordenada_t coord, Rect destination) {
    Rect rockRect(100, 220, 8, 8);
    CeldaUi cell(&ground, coord, destination, rockRect);
    map.push_back(cell);
}

void MapUi::addSand(coordenada_t coord, Rect destination) {
   Rect sandRect(0, 0, 8, 8);
   CeldaUi cell(&ground, coord, destination, sandRect);
   map.push_back(cell);

}

MapUi::~MapUi() = default;