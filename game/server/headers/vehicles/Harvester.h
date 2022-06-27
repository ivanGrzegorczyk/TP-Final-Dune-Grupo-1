#ifndef HARVESTER_H_
#define HARVESTER_H_

#include "common/headers/Vehicle.h"
#include "server/headers/map/ServerCell.h"

class Harvester : public Vehicle {
private:
    unsigned int spice;

public:
    Harvester(int playerId, int id, coordenada_t coord);

    void harvest(ServerCell *cell);
};

#endif  // HARVESTER_H_
