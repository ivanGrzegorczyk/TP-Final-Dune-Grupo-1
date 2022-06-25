#include "../headers/CreateBarracks.h"

std::vector<uint16_t> CreateBarracks::getData() {
    std::vector<uint16_t> data;
    data.push_back((uint16_t) BUILDING_BARRACKS);
    data.push_back((uint16_t)coord.first);
    data.push_back((uint16_t)coord.second);
    return data;
}

CreateBarracks::CreateBarracks(int x, int y) : coord({x, y}) {
}

int CreateBarracks::getCommand() {
    return CREATE_BUILDING_EVENT;
}
