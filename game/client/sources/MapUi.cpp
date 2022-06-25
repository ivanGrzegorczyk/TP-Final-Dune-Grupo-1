#include "../headers/MapUi.h"
#include "client/headers/BuildingFactory.h"


MapUi::MapUi(Renderer &renderer) : 
    rdr(renderer), 
    ground (renderer, Surface(DATA_PATH "/d2k_BLOXBASE.bmp")),
    harvester(Texture(renderer, Surface(DATA_PATH "/harvester.png"))),
    gui(Rect(400,0,100,200)){
    dst.SetX(0) = dst.SetY(0);
    dst.SetW(LENGTH_TILE) = dst.SetH(LENGTH_TILE);
}

void MapUi::update(Response *response) {
    response->update(this , rdr);
}

void MapUi::receiveMap(Protocol &protocol) {
    this->terrain = protocol.receiveTerrain();
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
                this->addRocks(coord, dst);
            }else {
                this->addSand(coord, dst);
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
    for(auto const& [playerId, unitsMap] : units) {
       for(auto const& [unitId, unit]: unitsMap) {
           unit->render();
       }
    }

    for(auto const& [playerId, building] : buildings) {
        for(auto  [buildingId, b]: building) {
            b->render();
        }
    }

    // render gui
    Texture* texture = nullptr;
    Rect zero;
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
    return this->moveCharacter(x/16,y/16,playerId);
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
    Rect rockRect(100, 220, 8, 8);
    CeldaUi cell(&ground, coord, destination, rockRect);
    map.push_back(cell);
}

void MapUi::addSand(coordenada_t coord, Rect destination) {
    Rect sandRect(0, 0, 8, 8);
    CeldaUi cell(&ground, coord, destination, sandRect);
    map.push_back(cell);
}

void MapUi::updateUnits(int player, int type, int characterId, coordenada_t coord) {
    if(units.find(player) != units.end()) {
        if(units[player].find(characterId) != units[player].end()) {
            units.at(player).at(characterId)->setPosition(coord);
        } else {
            units.at(player).insert(std::make_pair<int, Character*>
                    (int{characterId}, new Character(rdr, characterId, coord, type)));
        }
    } else {
        units[player].insert(std::make_pair<int, Character *>(int{characterId}, new Character(rdr, characterId, coord, type)));
    }
}

void MapUi::updateBuilding(int player, int type, int buildingId, coordenada_t coord) {
    BuildingFactory factory;
    buildings[player].insert(std::make_pair<int, SdlEntity*>
            (int{buildingId}, factory.createBuilding(type, buildingId, coord, rdr)));
}

MapUi::~MapUi() = default;