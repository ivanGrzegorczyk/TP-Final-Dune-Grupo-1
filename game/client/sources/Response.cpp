#include "../headers/Response.h"
#include "../headers/Character.h"

void Response::add(int playerId, int type, int characterId, coordenada_t coord) {
    if(units.find(playerId) != units.end()) {
        units.at(playerId).push_back(std::make_tuple(characterId, type, coord));
    } else {
        units[playerId].push_back(std::make_tuple(characterId, type, coord));;
    }
}

void Response::update(std::map<int, std::map<int, std::shared_ptr<Character>>> &unitsMap, Renderer &rdr) {
    for (auto const &[player, playerData]: this->units) {
        if (unitsMap.find(player) != unitsMap.end()) { //me fijo si existe el jugador
            this->iterate(unitsMap, playerData, rdr, true, player);
        } else {
            this->iterate(unitsMap, playerData, rdr, false, player);
        }
    }
}

void Response::iterate(std::map<int, std::map<int, std::shared_ptr<Character>>> &unitsData,
std::vector<std::tuple<int, int, coordenada_t>> playerData ,Renderer &rdr, bool containsPlayer, int player) {

    for(auto& data : playerData){
        int characterId = std::get<0>(data);
        int type = std::get<1>(data);
        coordenada_t coord = std::get<2>(data);
        if(containsPlayer) {
            if(unitsData[player].find(characterId) != unitsData[player].end()) {
                unitsData.at(player).at(characterId)->setPosition(coord); //actualizo
            } else {
                unitsData.at(player).insert(std::make_pair<int, Character *>(int{characterId}, new Character(rdr, characterId, coord, type)));
            }
        } else {
            unitsData[player].insert(std::make_pair<int, Character *>(int{characterId}, new Character(rdr, characterId, coord, type))); //creo jugador y unidad
        }
    }
}