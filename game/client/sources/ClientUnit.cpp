#include "client/headers/ClientUnit.h"

ClientUnit::ClientUnit(int playerId, int id, double hp, int range, int speed, int type, coordenada_t coord) :
        Entity(id, hp, type, coord), 
        range(range),
        speed(speed), 
        playerId(playerId) {
}

void ClientUnit::setPosition(coordenada_t newPosition) {
    this->coord = newPosition;
}
