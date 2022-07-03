#include "../headers/MoveQuery.h"


MoveQuery::MoveQuery(int id, coordenada_t &&dst) : unityId(id) , dest(dst){

}

std::vector<uint16_t> MoveQuery::getData() {
    std::vector<uint16_t> data(3, 0);
    data[0] = unityId;
    data[1] = dest.first;
    data[2] = dest.second;
    return data;
}

int MoveQuery::getCommand() {
    return REPOSITION_EVENT;
}
