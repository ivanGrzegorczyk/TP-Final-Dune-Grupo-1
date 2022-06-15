#include "../headers/MapUi.h"

#include <utility>

MapUi::MapUi(Renderer &renderer, std::string terrain) : terrain(std::move(terrain)), rdr(renderer), ground(renderer, Surface(DATA_PATH "/d2k_BLOXBASE.bmp")),
                                                  ground2(renderer, Surface(DATA_PATH "/d2k_BLOXXMAS.bmp")),
                                                  ground3(renderer, Surface(DATA_PATH "/d2k_BLOXTREE.bmp")){
    src.SetX(SRC);
    src.SetY(SRC);
    src.SetW(WIDTH_TEXTURE);
    src.SetH(HEIGHT_TEXTURE);
    dst.SetW(WIDTH_TEXTURE);
    dst.SetH(HEIGHT_TEXTURE);
    dst.SetX(SRC);
    dst.SetY(SRC);
    map.resize(50, std::vector<CeldaUi>(160));
    draw();
}
void MapUi::update(Response *response) {
    response->update(this->units, rdr);
    //for para recorrer el diccionario para actualizar posiciones
}

MapUi::~MapUi() {

}

void MapUi::draw() {
    std::string line;
    std::string columns; //frente 150 en y, 0 en x
    Rect s(0, 0, 8, 8);
    Rect r(8, 0, 8, 8);
    Rect sp(0, 312, 8, 8);
    //Rect rs(0, 0, 13,16);
    sand = s;
    rock = r;
    specie = sp;

    int numberRow = 0;
    std::fstream file;
    file.open(terrain);
    getline(file, columns);
    while (getline(file, line) && numberRow < 50) {
        for (int col = 0; col < (std::stoi(columns)); col++) {
            std::pair<int, int> coord;
            coord.first = numberRow;
            coord.second = col;
            char &g = line.at(col);
            dst.SetX(col * WIDTH_TEXTURE);
            dst.SetY(numberRow * HEIGHT_TEXTURE);
            if (g == 'X') {
                //extraigo datos del vector del server
                CeldaUi cell(&ground3, coord, dst, r);
                //rdr.Copy(ground3, r, dst);
                map[numberRow][col] = cell;
            } else if (g == 'S') {
                CeldaUi cell(&ground2, coord, dst, sp);
                map[numberRow][col] = cell;
                //rdr.Copy(ground2, sp, dst);
            } else {
                CeldaUi cell(&ground, coord, dst, s);
                map[numberRow][col] = cell;
                //rdr.Copy(ground, s, dst);
            }
        }
        numberRow++;
    }
}

void MapUi::render() {
    //rdr.Copy(ground, s, Rect(1000, 900, 32, 32));
    for(auto& row : map) {
        for(auto& col : row) {
            col.render(rdr);
        }
    }
   for(auto const& [playerId, unitsMap] : units) {
       for(auto const& [unitId, unit]: unitsMap) {
           unit->render();
       }
   }
}

Request* MapUi::mouseEvent(int x, int y, int playerId) {
    coordenada_t coord {x, y};
    for (auto const& [unitId, unit] : units.at(playerId)) {
        if(unit->getPosition() == coord) {
            return unit->reactToEvent(x, y);
        }
    }
    return nullptr;
    //return character.reactToEvent(x, y);
}

void MapUi::moveCharacter(std::vector<coordenada_t> &path) {
    //character.move(path);
}
