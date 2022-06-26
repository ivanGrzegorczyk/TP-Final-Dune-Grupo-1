#ifndef TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#define TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#include "SDL2pp/SDL2pp.hh"
#include "CeldaUi.h"
#include "Protocol.h"
#include "common/headers/Building.h"
#include "client/headers/gui/gui.h"
#include "character.h"
#include "SdlEntity.h"
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
    Texture harvester;
    GUI gui;
    std::pair<coordenada_t, std::vector<uint8_t>> terrain;
    //std::map<int, std::map<int, std::shared_ptr<Building>>> buildings; modificar, igual al de unidades
    std::map<int, std::map<int, SdlEntity*>> buildings;
    std::map<int, std::map<int, character*>> units;
    std::vector<CeldaUi> map;

public:
    explicit MapUi(Renderer& renderer);
    ~MapUi();
    void draw();
    Request* mouseEvent(int x, int y, int playerId);
    void update(Response *response);
    void receiveMap(Protocol &protocol);
    void render();

    Request* clickScreen(int x, int y, int playerId);
    Request* moveCharacter(int x, int y, int playerId);

    void addRocks(coordenada_t coord, Rect destination);
    void addSand(coordenada_t coord, Rect destination);

    void updateUnits(int player, int type, int characterId, coordenada_t coord);
    void updateBuilding(int player, int type, int buildingId, coordenada_t coord);
};


#endif //TP_FINAL_DUNE_GRUPO_1_MAPUI_H