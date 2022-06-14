#include "../headers/Response.h"
#include "../headers/Character.h"

/*void Response::addResponseChunk(uint16_t chunk) {
    response.push_back(chunk);
}*/

void Response::add(int playerId, int characterId, coordenada_t coord) {
    units.emplace(playerId, std::make_pair(characterId, coord));
}

void Response::update(std::map<int, std::map<int, std::shared_ptr<Character>>> unitsInfo) {
    for(auto const& [player, coordUnit] : this->units) {
        unitsInfo.at(player).at(coordUnit.first)->setPosition(coordUnit.second);
    }
}
