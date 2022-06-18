#include "../headers/CreateLightInfantry.h"

CreateLightInfantry::CreateLightInfantry(int x, int y) : coord({x, y}) {

}

std::vector<uint16_t> CreateLightInfantry::getData() {
    std::vector<uint16_t> data;
    data.push_back((uint16_t) UNIT_LIGHT_INFANTRY);
    data.push_back((uint16_t)coord.first);
    data.push_back((uint16_t)coord.second);
    return data;
}

int CreateLightInfantry::getCommand() {
    return CREATE_UNIT_EVENT;
}

