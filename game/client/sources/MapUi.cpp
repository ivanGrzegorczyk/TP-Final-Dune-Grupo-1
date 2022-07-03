#include "../headers/MapUi.h"
#include "client/headers/BuildingFactory.h"
#include "client/headers/BuildingUi.h"
#include "client/headers/CreateBuilding.h"
#include "../headers/MoveQuery.h"
#include "../headers/CreateLightInfantry.h"


MapUi::MapUi(Renderer &renderer) : 
        terrainRepo(renderer),
        rdr(renderer), 
        ground (renderer, Surface(DATA_PATH "/d2k_BLOXBASE.bmp")),
        harvester(Texture(renderer, Surface(DATA_PATH "/harvester.png"))),
        building_types(factory.createBuildingTypes(rdr)),
        gui(Rect(500,0,100,200), building_types, factory.createUnitTypes(rdr)) {
    dst.SetX(0) = dst.SetY(0);
    dst.SetW(LENGTH_TILE) = dst.SetH(LENGTH_TILE);
}

void MapUi::update(Response *response) {
    // Do not draw on next frame if server's snapshot does not include them
    previous_units = units;
    units.clear();
    buildings.clear();
    response->update(this , rdr);
}

void MapUi::receiveMap(std::shared_ptr<Protocol> protocol) {
    this->terrain = protocol->receiveTerrain();
}

void MapUi::draw() {
    int k = 0;
    for(int j = 0; j < this->terrain.first.first; j++) {
        for (int i = 0; i < this->terrain.first.second; i++) {
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
    for(auto& tile : map) {
        tile.render(rdr);
    }
    for(auto const& unit: units) {
       unit.second->render();
    }
    for(auto const& b : buildings) {
        b.second->render();
    }
    // render gui
    gui.render(rdr);
    rdr.Present();
}

// TODO: select with left click
Request* MapUi::handleEvent(SDL_Event event, int playerId) {
    Request* req = nullptr;
    uint16_t id;
    int mouse_x;
    int mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    if(event.type == SDL_KEYDOWN){
        switch (event.key.keysym.sym) {
            case SDLK_a:
                req = new CreateLightInfantry(mouse_x / LENGTH_TILE, mouse_y / LENGTH_TILE);
                break;
            case SDLK_b:
                id = (uint16_t)(selectedBuilding()->code());
                req = new CreateBuilding(mouse_x / LENGTH_TILE, mouse_y / LENGTH_TILE, id);
                break;
            case SDLK_x:
                // TODO use damage protocol
                damageBetween(1, 2);
                break;
        } 
    } else if(event.type == SDL_MOUSEBUTTONUP) {
        if(event.button.button ==  SDL_BUTTON_RIGHT) {
            if(gui.isOverPoint(mouse_x, mouse_y)) {
                gui.clickOver(mouse_x, mouse_y);
            } else {
                //TODO make proper math to translate click coordinate to map coordinate
                req = this->moveCharacter(mouse_x/LENGTH_TILE,mouse_y/LENGTH_TILE,playerId);
            } 
        } else if(event.button.button == SDL_BUTTON_LEFT) {
            selectUnits(event, playerId);
        }
    }
    return req;
}

// TODO: select with left click
void MapUi::selectUnits(SDL_Event event, int playerId) {
    for (auto const& unit : units) {
        if(unit.second->playerId == playerId) {
            if(unit.second->contains(event.button.x, event.button.y)) {
                std::cout << "selecting..." << std::endl;
                unit.second->setSelected(true);
            }
        }
    }
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

//TODO move multiple units at once!
Request* MapUi::moveCharacter(int x, int y, int playerId) {
    bool request;
    for (auto const& unit : units) {
        request = unit.second->walkEvent(x, y);
        if (request) {
            coordenada_t coord(x,y);
            std::cout <<  "unit id:" << unit.second->getId();
            std::cout <<  "x:" << x;
            std::cout <<  "y:" << y << std::endl;
            return new MoveQuery(unit.second->getId(), std::move(coord));
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
    // add player if not yet existent
    if(players.find(player) == players.end()) {
        players.insert(player);
    }
    // check if unit is in cache
    auto found = previous_units.find(characterId);
    if(found != previous_units.end()) {
        (*found).second->setPosition(coord);
        units.insert(*found);
    } else {
        character* c = new character(rdr, player, characterId, coord, type);
        auto pair = std::make_pair<int, std::shared_ptr<character >>  ((int)characterId, (std::shared_ptr<character>) std::shared_ptr<character>(c));
        units.insert(pair);
    }
    
}

Request* MapUi::damageBetween(int entity1, int entity2) {
    return nullptr;
}

/*
    Create new building on map
*/
void MapUi::updateBuilding(int player, int buildingId, std::shared_ptr<BuildingType> type, coordenada_t coord) {
    Point size(50,50);
    Point center(0,0);
    buildings.insert(
        std::make_pair<int, std::shared_ptr<BuildingUi>>(
            int{buildingId}, 
            std::shared_ptr<BuildingUi>(
                new BuildingUi(
                    player, 
                    buildingId,
                    type, 
                    rdr, 
                    coord, 
                    size,
                    center)))) ;
}

std::shared_ptr<BuildingType> MapUi::selectedBuilding() {
    return gui.getBuildingToBuild();
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

MapUi::~MapUi() = default;
