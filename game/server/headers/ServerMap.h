#ifndef SERVERMAP_H_
#define SERVERMAP_H_

#include <memory>
#include <map>

#include "ServerCell.h"
#include "Navigator.h"

class ServerMap {
private:
    std::map<int, std::shared_ptr<Building>> buildings;
    std::map<int, std::shared_ptr<Unity>> unities;
    std::vector<std::vector<ServerCell>> map;

    std::stack<coordenada_t> A_star(coordenada_t start, coordenada_t end);
public:
    ServerMap(int rows, int columns);

    bool reposition(int id, coordenada_t goal);
};

#endif  // SERVERMAP_H_
