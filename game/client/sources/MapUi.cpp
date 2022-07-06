#include "../headers/MapUi.h"
#include "client/headers/BuildingFactory.h"
#include "client/headers/BuildingUi.h"
#include "client/headers/CreateBuilding.h"
#include "../headers/MoveQuery.h"
#include "../headers/AttackRequest.h"
#include "../headers/CreateLightInfantry.h"
#include "client/headers/VehicleUi.h"
#include "client/headers/CreateHarvester.h"


MapUi::MapUi(Renderer &renderer) :
        repository(renderer),
        rdr(renderer),
        building_types(factory.createBuildingTypes(rdr)),
        gui(Rect(500,0,100,200), building_types, factory.createUnitTypes(rdr)),
        map_center({0,0}) {
}

// PROCESS INPUT


// TODO: select with left click
std::vector<Request*> MapUi::handleEvent(SDL_Event event, int playerId) {
    
    uint16_t id;
    int mouse_x;
    int mouse_y;
    uint32_t state = SDL_GetMouseState(&mouse_x, &mouse_y);
    int cell_x = mouse_x / LENGTH_TILE;
    int cell_y = mouse_y / LENGTH_TILE;
    std::vector<Request*> requests;
    // interact with gui
    if(event.type == SDL_MOUSEBUTTONDOWN
        && event.button.button == SDL_BUTTON_LEFT 
        && gui.isOverPoint(mouse_x, mouse_y)) {
            gui.clickOver(mouse_x, mouse_y);
            
    } else if(event.type == SDL_MOUSEBUTTONDOWN) {
        if(event.button.button == SDL_BUTTON_LEFT && pressed == false) {
            pressed = true;
        }
    } else if(event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_a:
                //audioPlayer.play();
                requests.push_back(new CreateLightInfantry(cell_x, cell_y));
                break;
            case SDLK_b:
                //audioPlayer.play();
                id = (uint16_t)(gui.getBuildingToBuild()->code());
                requests.push_back(new CreateBuilding(cell_x, cell_y, id));
                break;
            case SDLK_SPACE:
                map_center.first = mouse_x;
                map_center.second = mouse_y;
                break;
            case SDLK_h:
               requests.push_back(new CreateHarvester(cell_x, cell_y));
               break;
        } 
    } else if(event.type == SDL_MOUSEBUTTONUP) {
        if(event.button.button ==  SDL_BUTTON_RIGHT) {
            std::vector<Request*> _r = this->moveCharacter(cell_x,cell_y,playerId);
            requests.insert(requests.begin(),_r.begin(), _r.end());
        } else if(event.button.button == SDL_BUTTON_LEFT) {
            pressed = false;
            selectUnits(event, playerId);
        }
    } else if(event.type == SDL_MOUSEMOTION) {
        if(pressed == true) {
            selectUnits(event, playerId);
        }
    }
    return requests;
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

    for (auto const& vehicle : vehicles) {

            if(vehicle.second->contains(event.button.x, event.button.y)) {
                std::cout << "selecting..." << std::endl;
                vehicle.second->setSelected(true);
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
std::vector<Request*> MapUi::moveCharacter(int x, int y, int playerId) { //(x, y) posicion del enemigo o de un lugar del mapa
    std::vector<Request*> requests;
    std::cout << "units: " <<units.size() << std::endl;
    //recorrer para saber si es enemigo
    int id = INVALID_ENTITY_ID; //id de un enemigo
    for(auto const& unit : units) {
        if(unit.second->contains(x, y) && unit.second->playerId != playerId) {
           id = unit.second->getId();
        }
    }
    bool applies_to_unit;
    Request *request;
    for (auto const& unit : units) {
        Request *request;
        bool applies_to_unit;
        
        if(id != INVALID_ENTITY_ID) {
            std::cout << "attack event";
            applies_to_unit = unit.second->attackEvent(id);
            request = new AttackRequest(unit.second->getId(), id);
        } else {
            std::cout << "move event";
            applies_to_unit = unit.second->walkEvent(x, y);
            request = new MoveQuery(unit.second->getId(),coordenada_t({x,y}));
        }

        if(applies_to_unit) {
            requests.emplace_back(request);
            //break;
        }
    }

    for (auto const& vehicle : vehicles) {
        applies_to_unit = vehicle.second->walkEvent(x, y);
        request = new MoveQuery(vehicle.second->getId(),coordenada_t({x,y}));
        if(applies_to_unit) {
            requests.emplace_back(request);
            //break;
        }
    }
    return requests;
}

/*
*/


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
        character* c = new character(rdr, player, characterId, coord, type, repository);
        auto pair = std::make_pair<int, std::shared_ptr<character >>
        ((int)characterId, (std::shared_ptr<character>) std::shared_ptr<character>(c));
        units.insert(pair);
    }
}

void MapUi::updateVehicles(int player, int type, int vehicleId, coordenada_t coord) {
    if(players.find(player) == players.end()) {
        players.insert(player);
    }

    if(vehicles.find(vehicleId) != vehicles.end()) {
        vehicles[vehicleId]->setPosition(coord);
    } else {
        auto* vehicle = new VehicleUi(rdr, player, vehicleId, coord, type, repository);
        vehicles.emplace(vehicleId, vehicle);
    }
}



/*
    Create new building on map
*/
void MapUi::updateBuilding(int player, int buildingId, std::shared_ptr<BuildingType> type, coordenada_t coord) {
    Point size(50,50);
    Point location = fromCell(coord);
    buildings.insert(
        std::make_pair<int, std::shared_ptr<BuildingUi>>(
            int{buildingId}, 
            std::shared_ptr<BuildingUi>(
                new BuildingUi(
                    player, 
                    buildingId,
                    type, 
                    rdr, 
                    location, 
                    size)))) ;
}

void MapUi::updateTerrain(coordenada_t coord, int sand_level) {
    int width = this->terrain.first.first;
    int height = this->terrain.first.second;
    int index = coord.second * height + coord.first;

    auto &texture = repository.getTileOf(sand_level);

    map.at(index).setTexture(texture);
}

Point MapUi::fromCell(coordenada_t coord) {
    return Point(coord.first * LENGTH_TILE, coord.second * LENGTH_TILE);
}

void MapUi::receiveMap(std::shared_ptr<Protocol> protocol) {
    this->terrain = protocol->receiveTerrain();
}

void MapUi::draw() {
    int k = 0;
    for(int j = 0; j < this->terrain.first.first; j++) {
        for (int i = 0; i < this->terrain.first.second; i++) {
            coordenada_t coord(j,i);
            uint8_t type = this->terrain.second.at(k);
            addTerrain(coord, type);
            k++;
        }
   }
}

// RENDER

void MapUi::render() {
    rdr.Clear();
    //updateVehicles(1, VEHICLE_HARVESTER, 10, coordenada_t{0 ,0});
    for(auto& tile : map) {
        tile.render(rdr);
    }
    for(auto const& unit: units) {
       unit.second->render();
    }
    for(auto const& b : buildings) {
        b.second->render();
    }

    for(auto const& b : vehicles) {
        b.second->render();
    }
    // render gui
    gui.render(rdr);
    gui.money = money;
    rdr.Present();
}


void MapUi::addTerrain(coordenada_t coord, int terrainId) {
    Point location = fromCell(coord);
    Point size = Point(LENGTH_TILE,LENGTH_TILE);
    Rect dst(location, size);
    SDL2pp::Texture &r =  repository.getTileOf(terrainId);
    Rect rockRect(0,0,16,16);
    CeldaUi cell(r, coord, dst, rockRect);
    map.push_back(std::move(cell));
    std::cout << "cell coord:" << coord.first << "," << coord.second << std::endl;
}


MapUi::~MapUi() = default;
