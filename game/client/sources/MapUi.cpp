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

// PROCESS INPUT


// TODO: select with left click
Request* MapUi::handleEvent(SDL_Event event, int playerId) {
    Request* req = nullptr;
    uint16_t id;
    int mouse_x;
    int mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    int cell_x = mouse_x / LENGTH_TILE;
    int cell_y = mouse_y / LENGTH_TILE;
    // interact with gui
    if(event.type == SDL_MOUSEBUTTONDOWN
        && event.button.button == SDL_BUTTON_LEFT 
        && gui.isOverPoint(mouse_x, mouse_y)) {
            gui.clickOver(mouse_x, mouse_y);
    } else if(event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_a:
                req = new CreateLightInfantry(cell_x, cell_y);
                break;
            case SDLK_b:
                id = (uint16_t)(gui.getBuildingToBuild()->code());
                req = new CreateBuilding(cell_x, cell_y, id);
                break;
            case SDLK_x:
                // TODO use damage protocol
                damageBetween(1, 2);
                break;
        } 
    } else if(event.type == SDL_MOUSEBUTTONUP) {
        if(event.button.button ==  SDL_BUTTON_RIGHT) {
            req = this->moveCharacter(cell_x,cell_y,playerId);
            
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

Request* MapUi::damageBetween(int entity1, int entity2) {
    return nullptr;
}


// UPDATE

void MapUi::update(Response *response) {
    // Do not draw on next frame if server's snapshot does not include them
    previous_units = units;
    units.clear();
    buildings.clear();
    response->update(this , rdr);
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
            addTerrain(coord, dst, type);
            k++;
        }
   }
}

// RENDER

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



void MapUi::addTerrain(coordenada_t coord, Rect destination, int terrainId) {
   // Rect rockRect(100, 220, 8, 8);
   try {
        SDL2pp::Texture &r =  terrainRepo.getTileOf(terrainId);
        Rect rockRect(0,0,16,16);
        CeldaUi cell(r, coord, destination, rockRect);
        map.push_back(cell);
   } catch(std::exception e) {
       std::cout << "terrain error:" << e.what() << std::endl;
   }
}


MapUi::~MapUi() = default;
