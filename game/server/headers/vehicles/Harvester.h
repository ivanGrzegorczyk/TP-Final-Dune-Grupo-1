#ifndef HARVESTER_H_
#define HARVESTER_H_

#include "Vehicle.h"
#include "server/headers/map/ServerCell.h"

class Harvester : public Vehicle {
private:
    unsigned int spice;

public:
    Harvester(int id, coordenada_t coord);

    void harvest(ServerCell *cell);

    std::shared_ptr<Vehicle> copy() override;
};

#endif  // HARVESTER_H_
