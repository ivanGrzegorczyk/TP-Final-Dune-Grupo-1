#ifndef TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#define TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#include "SDL2pp/SDL2pp.hh"
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>

#include "../headers/CeldaUi.h"
#include "../headers/Character.h"
#include "../../common/headers/Building.h"

#define WIDTH_TEXTURE 16
#define HEIGHT_TEXTURE 16
#define SRC 0

using namespace SDL2pp;

class MapUi {
private:
    void draw();
    Character character;
    Rect src;
    Rect dst;
    Renderer& rdr;
    Texture ground;
    Texture ground2;
    Texture ground3;
    Rect rock;
    Rect sand;
    Rect specie;
    //std::map<int, std::map<int, std::shared_ptr<Building>>> buildings;
    std::map<int, std::map<int, std::shared_ptr<Units>>> units;
    std::vector<std::vector<CeldaUi>> map;

public:
    MapUi(Renderer& renderer, char* terrain);
    ~MapUi();
    char* terrain;
    Request* mouseEvent(int x, int y);
    void update(Response *response);
    void render();

    void moveCharacter(std::vector<coordenada_t> &path);

};


#endif //TP_FINAL_DUNE_GRUPO_1_MAPUI_H
