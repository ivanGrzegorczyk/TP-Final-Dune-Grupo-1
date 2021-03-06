#ifndef TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#define TP_FINAL_DUNE_GRUPO_1_MAPUI_H
#include "SDL2pp/SDL2pp.hh"
#include "Request.h"
#include "CeldaUi.h"
#include "Protocol.h"
#include "common/headers/Building.h"
#include "client/headers/gui/gui.h"
#include "client/headers/character.h"
#include "client/headers/BuildingUi.h"
#include "client/headers/building_type/BuildingType.h"
#include "character.h"
#include "SdlEntity.h"
#include "TextureManager.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <memory>
#include "client/headers/BuildingFactory.h"
#include "../headers/character.h"
#include "client/headers/audio/audioPlayer.h"
#include "VehicleUi.h"

#define LENGTH_TILE 16
using namespace SDL2pp;

class MapUi {
private:
    coordenada_t map_center;
    Rect dst;
    TextureManager repository;
    Renderer& rdr;
    BuildingFactory factory;
    std::vector<std::shared_ptr<BuildingType>> building_types;
    std::unordered_set<int> players;
    GUI gui;
    std::pair<coordenada_t, std::vector<uint8_t>> terrain;
    std::map<int, VehicleUi*> vehicles;
    //std::map<int, std::map<int, std::shared_ptr<Building>>> buildings; modificar, igual al de unidades
    std::map<int, std::shared_ptr<BuildingUi>> buildings; //buildings to draw
    std::unordered_map<int, std::shared_ptr<character>> units; //units to draw
    std::unordered_map<int, std::shared_ptr<character>> previous_units;
    std::vector<CeldaUi> map;
    Point fromCell(coordenada_t coord);
    bool pressed = false;
    AudioPlayer audioPlayer;
public:
    int money;
    explicit MapUi(Renderer& renderer);
    ~MapUi();
    void draw();
    void selectUnits(SDL_Event event, int playerId);
    void update(Response *response);
    void receiveMap(std::shared_ptr<Protocol> protocol);
    void render();
    std::vector<Request*> handleEvent(SDL_Event event, int playerId);
    std::vector<Request*> moveCharacter(int x, int y, int playerId);

    std::shared_ptr<BuildingType> selectedBuilding();
    std::shared_ptr<BuildingType> getBuildingType(int type);
    void updateBuilding(int playerId, int buildingId,  std::shared_ptr<BuildingType> type, coordenada_t coord);
    void updateUnits(int player, int type, int characterId, coordenada_t coord);
    void updateTerrain(coordenada_t coord, int sand_level = 0);
    void addTerrain(coordenada_t coord, int terrainId);

    void updateVehicles(int player, int type, int vehicleId, coordenada_t coord);
};


#endif //TP_FINAL_DUNE_GRUPO_1_MAPUI_H