#ifndef TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#define TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#include "SDL2pp/SDL2pp.hh"
#include "Character.h"
#include "CeldaUi.h"
#include "Response.h"
#include "Protocol.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>


#define WIDTH_TEXTURE 16
#define HEIGHT_TEXTURE 16
#define SRC 0

using namespace SDL2pp;

class MapUi {
private:
    void draw();
    Rect src;
    Rect dst;
    Renderer& rdr;
    Texture ground;
    Texture ground2;
    Texture ground3;
    Rect rock;
    Rect sand;
    Rect specie;
    std::pair<coordenada_t, std::vector<uint8_t>> terrain;
    //std::map<int, std::map<int, std::shared_ptr<Building>>> buildings;
    std::map<int, std::map<int, std::shared_ptr<Character>>> units;
    std::vector<std::vector<CeldaUi>> map;

public:
    MapUi(Renderer& renderer, std::string terrain);
    ~MapUi();
    //std::string  terrain;
    Request* mouseEvent(int x, int y, int playerId);
    void update(Response *response);
    void receiveMap(Protocol &protocol);
    void render();

    Request* moveCharacter(int x, int y, int playerId);

};


#endif //TP_FINAL_DUNE_GRUPO_1_MAPUI_H
