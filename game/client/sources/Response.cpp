#include "../headers/Response.h"
#include "../headers/Character.h"

/*void Response::addResponseChunk(uint16_t chunk) {
    response.push_back(chunk);
}*/

void Response::add(int playerId, int characterId, coordenada_t coord) {
    units.emplace(playerId, std::make_pair(characterId, coord));
}

void Response::update(std::map<int, std::map<int, std::shared_ptr<Character>>> &unitsMap, Renderer &rdr) {
    for(auto const& [player, coordUnit] : this->units) {
        if(unitsMap.find(player) != unitsMap.end()) { //me fijo si existe el jugador

            if(unitsMap[player].find(coordUnit.first) != unitsMap[player].end()) {
                unitsMap.at(player).at(coordUnit.first)->setPosition(coordUnit.second); //actualizo
            } else {
                unitsMap.at(player).insert(std::pair<int, Character *> (
                        coordUnit.first, new Character(rdr, coordUnit.first, coordUnit.second))); //creo unidad
            }

        } else {
            unitsMap[player].insert(std::pair<int, Character *> (
                    coordUnit.first, new Character(rdr, coordUnit.first, coordUnit.second))); //creo jugador y unidad
        }
    }
}
