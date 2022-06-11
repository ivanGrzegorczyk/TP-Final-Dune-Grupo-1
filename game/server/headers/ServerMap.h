#ifndef SERVERMAP_H_
#define SERVERMAP_H_

#include <memory>
#include <map>

#include "ServerCell.h"
#include "Navigator.h"

class ServerMap {
private:
    int rows, columns;
    std::map<coordenada_t, std::shared_ptr<Building>> buildings;

public:
    ServerMap(int rows, int columns);

    std::vector<std::vector<ServerCell>> map;

    std::stack<coordenada_t> A_star(coordenada_t start, coordenada_t end);
};

#endif  // SERVERMAP_H_
