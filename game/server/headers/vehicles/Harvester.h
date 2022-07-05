#ifndef HARVESTER_H_
#define HARVESTER_H_

#include "Vehicle.h"
#include "server/headers/map/ServerCell.h"
#include "server/headers/buildings/Refinery.h"

class Harvester : public Vehicle {
private:
    int spice;
    bool unloading;
    int refinery;
    coordenada_t working_position;
    Chronometer chronometer;

public:
    Harvester(int id, coordenada_t coord);

    Harvester(int id, int spice, coordenada_t coord);

    void harvest(ServerCell *cell);

    std::shared_ptr<Vehicle> copy() override;

    int getSpice() const;

    bool isFull() const;

    bool isUnloading() const;

    coordenada_t relocate() override;

    bool isEmpty() const;

    void setUnloading(bool _unloading);

    void setRefinery(int _refinery);

    int getRefinery() const;

    unsigned int unload(std::shared_ptr<Refinery> &goal);

    coordenada_t getWorkingPosition() const;

    void setWorkingPosition(coordenada_t position);
};

#endif  // HARVESTER_H_
