#ifndef TP_FINAL_DUNE_GRUPO_1_RESPONSE_H
#define TP_FINAL_DUNE_GRUPO_1_RESPONSE_H

#include <cstdint>
#include <vector>
#include <map>
#include <memory>
#include "../../common/headers/Constantes.h"
#include "Character.h"


class Response {
private:
    //std::vector<uint16_t> response;
    std::map<int, std::vector<std::tuple<int, int, coordenada_t>>> units;

public:
    Response() = default;
    void add(int playerId, int type, int characterId, coordenada_t coord);
    void update(std::map<int, std::map<int, std::shared_ptr<Character>>> &unitsInfo, Renderer &rdr);
    void iterate(std::map<int, std::map<int, std::shared_ptr<Character>>> &unitsData,
    std::vector<std::tuple<int, int, coordenada_t>>,Renderer &rdr, bool containsPlayer, int player);
};

#endif //TP_FINAL_DUNE_GRUPO_1_RESPONSE_H
