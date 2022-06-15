#ifndef SERVERCELL_H_
#define SERVERCELL_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <memory>

#include "../../common/headers/Building.h"
#include "../../common/headers/Unity.h"

class ServerCell {
public:
    coordenada_t id;
    char ground;  // Temporal para simular celdas ocupadas
    std::shared_ptr<Building> building;
    std::vector<std::weak_ptr<Unity>> unities;

    // Unidades en la celda
    // Edificios en la celda

    ServerCell();
    explicit ServerCell(coordenada_t coord);
};

#endif  // SERVERCELL_H_
