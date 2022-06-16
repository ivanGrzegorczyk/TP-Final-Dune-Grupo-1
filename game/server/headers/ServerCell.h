#ifndef SERVERCELL_H_
#define SERVERCELL_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <memory>

#include "../../common/headers/Building.h"
#include "../../common/headers/Unit.h"

#define TERRAIN_SAND 0
#define TERRAIN_DUNES 1
#define TERRAIN_ROCKS 2
#define TERRAIN_TOPS 3
#define TERRAIN_CLIFFS 4

class ServerCell {
public:
    coordenada_t coords;
    int ground;
    std::shared_ptr<Building> building;
    std::vector<std::weak_ptr<Unit>> unities;

    ServerCell();
    explicit ServerCell(coordenada_t coord);
};

#endif  // SERVERCELL_H_
