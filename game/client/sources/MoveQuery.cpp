#include "../headers/MoveQuery.h"


MoveQuery::MoveQuery(int id, coordenada_t &&dst) : unityId(id) , dest(dst){

}

std::vector<uint16_t> MoveQuery::getData() {
    std::vector<uint16_t> data;
    data.push_back((uint16_t)unityId);
    data.push_back((uint16_t)dest.first);
    data.push_back((uint16_t)dest.second);
    return data;
}

int MoveQuery::getCommand() {
    return REPOSITION_EVENT;
}
