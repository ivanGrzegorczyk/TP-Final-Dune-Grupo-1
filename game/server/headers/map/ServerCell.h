#ifndef SERVERCELL_H_
#define SERVERCELL_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <memory>

#include "common/headers/Building.h"
#include "common/headers/Unit.h"

class ServerCell {
public:
    coordenada_t coords;
    std::shared_ptr<Building> building;
    std::vector<std::weak_ptr<Unit>> cellUnits;

    ServerCell();
    explicit ServerCell(coordenada_t coord);

    virtual int ground() = 0;
    virtual bool receiveUnit() = 0;
};

#endif  // SERVERCELL_H_