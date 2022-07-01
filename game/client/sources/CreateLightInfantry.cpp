#include "../headers/CreateLightInfantry.h"

CreateLightInfantry::CreateLightInfantry(int x, int y) : coord({x, y}) {

}

std::vector<uint16_t> CreateLightInfantry::getData() {
    std::vector<uint16_t> data(3,0);
    data[0] = UNIT_LIGHT_INFANTRY;
    data[1] = coord.first;
    data[2] = coord.second;
    return data;
}

int CreateLightInfantry::getCommand() {
    return CREATE_UNIT_EVENT;
}
