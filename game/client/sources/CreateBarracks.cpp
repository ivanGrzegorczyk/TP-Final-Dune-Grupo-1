#include "../headers/CreateBuilding.h"

std::vector<uint16_t> CreateBuilding::getData() {
    return {};
}

CreateBuilding::CreateBuilding(int x, int y) : coord({x, y}) {
    
}

int CreateBuilding::getCommand() {
    return CREATE_BUILDING_EVENT;
}
