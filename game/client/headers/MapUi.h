#ifndef TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#define TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#include "SDL2pp/SDL2pp.hh"
#include "Character.h"
#include "CeldaUi.h"
#include "Response.h"
#include "Protocol.h"
#include "common/headers/Building.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>


#define LENGTH_TILE 16
using namespace SDL2pp;

class MapUi {
private:
    Rect dst;
    Renderer& rdr;
    Texture ground;
    std::pair<coordenada_t, std::vector<uint8_t>> terrain;
    std::map<int, std::map<int, std::shared_ptr<Building>>> buildings;
    std::map<int, std::map<int, std::shared_ptr<Character>>> units;
    std::vector<CeldaUi> map;

public:
    explicit MapUi(Renderer& renderer);
    ~MapUi();
    void draw();
    //std::string  terrain;
    Request* mouseEvent(int x, int y, int playerId);
    void update(Response *response);
    void receiveMap(Protocol &protocol);
    void render();

    Request* moveCharacter(int x, int y, int playerId);

    void addRocks(coordenada_t coord, Rect destination);
    void addSand(coordenada_t coord, Rect destination);

};


#endif //TP_FINAL_DUNE_GRUPO_1_MAPUI_H
