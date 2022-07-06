#include <iostream>
#include "client/headers/CreateHeavyInfantry.h"

CreateHeavyInfantry::CreateHeavyInfantry(int x, int y) : coord({x, y}) {

}

std::vector<uint16_t> CreateHeavyInfantry::getData() {
    std::vector<uint16_t> data(3,0);
    std::cout <<  "create:" << UNIT_HEAVY_INFANTRY << ",";
    std::cout <<  "x:" << coord.first;
    std::cout <<  "y:" << coord.second << std::endl;
    data[0] = UNIT_HEAVY_INFANTRY;
    data[1] = coord.first;
    data[2] = coord.second;
    return data;
}

int CreateHeavyInfantry::getCommand() {
    return CREATE_UNIT_EVENT;
}
