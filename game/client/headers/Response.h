#ifndef TP_FINAL_DUNE_GRUPO_1_RESPONSE_H
#define TP_FINAL_DUNE_GRUPO_1_RESPONSE_H

#include <cstdint>
#include <vector>
#include <map>
#include <memory>
#include "Character.h"



class Response {
private:
    //std::vector<uint16_t> response;
    std::map<int, std::pair<int, coordenada_t>> units;

public:
    Response() = default;
    void add(int playerId, int characterId, coordenada_t coord);
    void update(std::map<int, std::map<int, std::shared_ptr<Character>>> &unitsInfo, Renderer &rdr);
    //void addResponseChunk(uint16_t chunk);
};


#endif //TP_FINAL_DUNE_GRUPO_1_RESPONSE_H
