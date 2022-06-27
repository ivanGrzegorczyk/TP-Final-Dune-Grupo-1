#include "client/headers/ClientUnit.h"

ClientUnit::ClientUnit(int playerId, int id, double hp, int range, int speed, int type, coordenada_t coord) :
        Entity(playerId, id, hp, type, coord), range(range), speed(speed) {
}

void ClientUnit::setPosition(coordenada_t newPosition) {
    this->coord = newPosition;
}
