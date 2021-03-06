#ifndef SERVERCELL_H_
#define SERVERCELL_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <memory>

#include "server/headers/buildings/Building.h"
#include "server/headers/units/Unit.h"
#include "common/headers/Chronometer.h"

#define MAX_SPICE 200

class ServerCell {
public:
    coordenada_t coords;
    bool occupied;
    Chronometer chronometer;

    ServerCell();
    explicit ServerCell(coordenada_t coord);

    virtual int ground() = 0;
    virtual unsigned int harvest() = 0;
    virtual bool harvestable();

    virtual ~ServerCell() = default;

    virtual int getSpice();
};

#endif  // SERVERCELL_H_
