#ifndef TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#define TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#include "SDL2pp/SDL2pp.hh"
#include <vector>
#include <fstream>
#include <sstream>
#include "Character.h"
#include "CeldaUi.h"
#define WIDTH_TEXTURE 16
#define HEIGHT_TEXTURE 16
#define SRC 0

using namespace SDL2pp;

class MapUi {
public:
    MapUi(Renderer& renderer, char* terrain);
    ~MapUi();
    char* terrain;
    bool mouseEvent(int x, int y, std::pair<coordenada_t, coordenada_t> &ubication);
    void update();
    void render();

    void moveCharacter(std::vector<coordenada_t> &path);

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
    std::vector<std::vector<CeldaUi>> map;
};


#endif //TP_FINAL_DUNE_GRUPO_1_MAPUI_H