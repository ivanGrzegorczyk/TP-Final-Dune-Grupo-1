#include <iostream>
#include "client/headers/CreateHarvester.h"

CreateHarvester::CreateHarvester(int x, int y) : coord({x, y}){
}

std::vector<uint16_t> CreateHarvester::getData() {
    std::vector<uint16_t> data(3,0);
    std::cout <<  "create:" << VEHICLE_HARVESTER << ",";
    std::cout <<  "x:" << coord.first;
    std::cout <<  "y:" << coord.second << std::endl;
    data[0] = VEHICLE_HARVESTER;
    data[1] = coord.first;
    data[2] = coord.second;
    return data;
}

int CreateHarvester::getCommand() {
    return CREATE_VEHICLE_EVENT;
}
