#include "../headers/CreateBuilding.h"

std::vector<uint16_t> CreateBuilding::getData() {
    std::vector<uint16_t> data;
    data.push_back((uint16_t) typeId);
    data.push_back((uint16_t)coord.first);
    data.push_back((uint16_t)coord.second);
    return data;
}

CreateBuilding::CreateBuilding(int x, int y, int typeId) : coord({x, y}), typeId(typeId) {
}

int CreateBuilding::getCommand() {
    return CREATE_BUILDING_EVENT;
}
