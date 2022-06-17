#include "../headers/MapUi.h"

#include <utility>

MapUi::MapUi(Renderer &renderer, std::string terrain) : rdr(renderer), ground (renderer, Surface(DATA_PATH "/d2k_BLOXBASE.bmp")),
                                               ground2(renderer, Surface(DATA_PATH "/d2k_BLOXXMAS.bmp")),
                                               ground3(renderer, Surface(DATA_PATH "/d2k_BLOXTREE.bmp")){
    std::cout << "Entra al constructor de MapUI" << std::endl;
    src.SetX(SRC);
    src.SetY(SRC);
    src.SetW(WIDTH_TEXTURE);
    src.SetH(HEIGHT_TEXTURE);
    dst.SetW(WIDTH_TEXTURE);
    dst.SetH(HEIGHT_TEXTURE);
    dst.SetX(SRC);
    dst.SetY(SRC);
    map.resize(50, std::vector<CeldaUi>(160));
}
void MapUi::update(Response *response) {
    response->update(this->units, rdr);
}


void MapUi::receiveMap(Protocol &protocol) {
    this->terrain = protocol.receiveTerrain();
    map = std::vector<std::vector<CeldaUi>>(
            terrain.first.first, std::vector<CeldaUi>(terrain.first.second));
}


void MapUi::draw() {
    std::cout << "Entra al MapUi.draw()" << std::endl;
    std::string line;
    std::string columns; //frente 150 en y, 0 en x
    Rect s(0, 0, 8, 8);
    Rect r(8, 0, 8, 8);
    Rect sp(0, 312, 8, 8);
    //Rect rs(0, 0, 13,16);
    sand = s;
    rock = r;
    specie = sp;

    for(int i = 0; i < this->terrain.first.first; i++) {
        for (int j = 0; j < this->terrain.first.second; j++) {
            std::pair<int, int> coord(i, j);
            dst.SetX(j * WIDTH_TEXTURE);
            dst.SetY(i * HEIGHT_TEXTURE);
            uint8_t type = this->terrain.second.at(j);
            if(type == TERRAIN_ROCKS) {
                CeldaUi cell(&ground3, coord, dst, r);
                map[i][j] = cell;
            }else {
                CeldaUi cell(&ground, coord, dst, s);
                map[i][j] = cell;
            }
        }
   }
}

void MapUi::render() {
    rdr.Clear();
    //rdr.Copy(ground, s, Rect(1000, 900, 32, 32));
    for(auto& row : map) {
        for(auto& col : row) {
            col.render(rdr);
        }
    }
    //std::cout << "tamaño de arreglo: " << units.size() << std::endl;
    for(auto const& [playerId, unitsMap] : units) {
       for(auto const& [unitId, unit]: unitsMap) {
           unit->render();
       }
    }
    rdr.Present();
}

Request* MapUi::mouseEvent(int x, int y, int playerId) {
    for (auto const& [unitId, unit] : units[playerId]) {
        return unit->reactToEvent(x, y);
    }
    return nullptr;
}

Request* MapUi::moveCharacter(int x, int y, int playerId) {
    for (auto const& [unitId, unit] : units[playerId]) {
        return unit->walkEvent(x, y);
    }
    return nullptr;
}

MapUi::~MapUi() = default;