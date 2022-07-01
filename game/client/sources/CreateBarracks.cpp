#include "../headers/CreateBarracks.h"

std::vector<uint16_t> CreateBarracks::getData() {
    std::vector<uint16_t> data(3, 0);
    data[0] = BUILDING_BARRACKS;
    data[1] = coord.first;
    data[2] = coord.second;
    return data;
}

CreateBarracks::CreateBarracks(int x, int y) : coord({x, y}) {
}

int CreateBarracks::getCommand() {
    return CREATE_BUILDING_EVENT;
}
