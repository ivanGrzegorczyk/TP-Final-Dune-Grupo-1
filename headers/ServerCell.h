#ifndef SERVERCELL_H_
#define SERVERCELL_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

typedef std::pair<int, int> coordenada_t;

class ServerCell {
public:
    coordenada_t id;
    char ground;  // Temporal para simular celdas ocupadas

    // Unidades en la celda
    // Edificios en la celda

    ServerCell();
    explicit ServerCell(coordenada_t coord);
};

#endif  // SERVERCELL_H_
