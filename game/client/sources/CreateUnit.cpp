#include "../headers/CreateUnit.h"
#include <iostream>
CreateUnit::CreateUnit(int x, int y, int unit) : unit(unit), coord({x, y}) {}

std::vector<uint16_t> CreateUnit::getData() {
    std::vector<uint16_t> data(3,0);
    std::cout <<  "create:" << unit << ",";
    std::cout <<  "x:" << coord.first;
    std::cout <<  "y:" << coord.second << std::endl;
    data[0] = UNIT_LIGHT_INFANTRY;
    data[1] = coord.first;
    data[2] = coord.second;
    return data;
}

int CreateUnit::getCommand() {
    return CREATE_UNIT_EVENT;
}
