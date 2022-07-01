#include "../headers/MapUi.h"
#include "client/headers/BuildingFactory.h"
#include "client/headers/BuildingUi.h"


MapUi::MapUi(Renderer &renderer) : terrainRepo(renderer),
                                   rdr(renderer),
                                   ground (renderer, DATA_PATH "/sand1.png"),
                                   harvester(Texture(renderer, Surface(DATA_PATH "/harvester.png"))),
                                   gui(Rect(500,0,100,200), building_types, factory.createUnitTypes(rdr)) {
    dst.SetX(0) = dst.SetY(0);
    dst.SetW(LENGTH_TILE) = dst.SetH(LENGTH_TILE);
}

void MapUi::update(Response *response) {
    response->update(this , rdr);
}

void MapUi::receiveMap(std::shared_ptr<Protocol> protocol) {
    this->terrain = protocol->receiveTerrain();
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
                addRocks(coord, dst);
            } else if(type == TERRAIN_CLIFFS) {
                addCliff(coord, dst);
            } else if(type == TERRAIN_TOPS) {
                addTop(coord, dst);
            } else if(type == TERRAIN_DUNES) {
                addDune(coord, dst);
            } else {
                addSand(coord, dst);
            }
            k++;
        }
   }
}

void MapUi::render() {
    rdr.Clear();
    // render tiles
    for(auto& tile : map) {
        tile.render(rdr);
    }
    // render units
    //std::cout << "size: " << units.size() << std::endl;
    for(auto const& [playerId, unitsMap] : units) {
       for(auto const& [unitId, unit]: unitsMap) {
           unit->render();
       }
    }
    //std::cout << "size despues: " << units.size() << std::endl;
    for(auto const& [playerId, building] : buildings) {
        for(auto  [buildingId, b]: building) {
            b->render();
        }
    }

    // render gui
    gui.render(rdr);
    rdr.Present();
}

// TODO: replace with less generic name, use inside clickScreen
Request* MapUi::mouseEvent(int x, int y, int playerId) {
    for (auto const& [unitId, unit] : units[playerId]) {
        unit->reactToEvent(x, y);
    }
    return nullptr;
}

// todo take type of click as input or specify it in function name
Request* MapUi::clickScreen(int x, int y, int playerId) {
    if(gui.isOverPoint(x,y)) {
        gui.clickOver(x,y);
        return nullptr;
    }
    //TODO make proper math to translate click coordinate to map coordinate
    return this->moveCharacter(x/LENGTH_TILE,y/LENGTH_TILE,playerId);
}

// TODO use map instead of find if
std::shared_ptr<BuildingType> MapUi::getBuildingType(int type) {
    auto found = std::find_if(
        building_types.begin(), 
        building_types.end(), 
        [type](std::shared_ptr<BuildingType> b){
            return b->code() == type;
        });
    if(found == building_types.end()) {
        throw std::invalid_argument("bad building code");
    }
    return *found;
}

Request* MapUi::moveCharacter(int x, int y, int playerId) {
    Request *request;
    for (auto const& [unitId, unit] : units[playerId]) {
        request = unit->walkEvent(x, y);
        if (request != nullptr) {
            return request;
        } 
    }
    return nullptr;
}

void MapUi::addRocks(coordenada_t coord, Rect destination) {
   // Rect rockRect(100, 220, 8, 8);
   SDL2pp::Texture &r =  terrainRepo.getTileOf(TERRAIN_ROCKS);
   Rect rockRect(0,0,16,16);
   CeldaUi cell(r, coord, destination, rockRect);
    map.push_back(cell);
}

void MapUi::addSand(coordenada_t coord, Rect destination) {
    Rect sandRect(0, 0, 16, 16);
    SDL2pp::Texture &s =  terrainRepo.getTileOf(TERRAIN_SAND);
    CeldaUi cell(s, coord, destination, sandRect);
    map.push_back(cell);
}

void MapUi::updateUnits(int player, int type, int characterId, coordenada_t coord) {
    if(units.find(player) != units.end()) {
        if(units[player].find(characterId) != units[player].end()) {
            units.at(player).at(characterId)->setPosition(coord);
        } else {
            units.at(player).insert(std::make_pair<int, character*>
                    (int{characterId}, new character(rdr, player, characterId, coord, type)));
        }
    } else {
        units[player].insert(std::make_pair<int, character *>
                (int{characterId}, new character(rdr, player, characterId, coord, type)));
    }
}

/*
    Create new building on map
*/
void MapUi::spawnBuilding(int player, int buildingId, std::shared_ptr<BuildingType> type, coordenada_t coord) {
    auto found = buildings[player].find(buildingId);
    if(found != buildings[player].end()) {
        return;
    }
    std::cout << "new building" << std::endl;
    Point size(50,50);
    Point center(0,0);
    buildings[buildingId].insert(
        std::make_pair<int, SdlEntity*>(
            int{buildingId}, 
            new BuildingUi(
                player, 
                buildingId,
                type, 
                rdr, 
                coord, 
                size,
                center))) ;
    //buildings[player].emplace(buildingId, e);
    //insert({buildingId, e});
}

void MapUi::addCliff(coordenada_t coord, Rect destination) {
    Rect cliffRect(0, 0, 16, 16);
    SDL2pp::Texture &s =  terrainRepo.getTileOf(TERRAIN_CLIFFS);
    CeldaUi cell(s, coord, destination, cliffRect);
    map.push_back(cell);
}

void MapUi::addTop(coordenada_t coord, Rect destination) {
    Rect topRect(0, 0, 16, 16);
    SDL2pp::Texture &top =  terrainRepo.getTileOf(TERRAIN_TOPS);
    CeldaUi cell(top, coord, destination, topRect);
    map.push_back(cell);
}

void MapUi::addDune(coordenada_t coord, Rect destination) {
    Rect duneRect(0, 0, 16, 16);
    SDL2pp::Texture &d =  terrainRepo.getTileOf(TERRAIN_DUNES);
    CeldaUi cell(d, coord, destination, duneRect);
    map.push_back(cell);
}

std::shared_ptr<BuildingType> MapUi::selectedBuilding() {
    return gui.getBuildingToBuild();
}

MapUi::~MapUi() = default;
