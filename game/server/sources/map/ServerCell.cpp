#include "server/headers/map/ServerCell.h"

#include <utility>

ServerCell::ServerCell() : coords({0, 0}), occupied(false) {}

ServerCell::ServerCell(coordenada_t coord) : coords(std::move(coord)), occupied(false) {}

bool ServerCell::harvestable() {
    return false;
}
