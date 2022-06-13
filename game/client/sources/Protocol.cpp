#include <stack>
#include "../headers/Protocol.h"

Protocol::Protocol(const char* hostname, const char* servicename) : id(-1), skt(hostname, servicename){
    receiveId();
}

void Protocol::receiveId() {
    uint16_t idProtocol;
    skt.recvall(&idProtocol, sizeof(idProtocol));
    this->id = ntohs(idProtocol);
}

int Protocol::getId() const {
    return this->id;
}

int Protocol::commandReceive() {
    uint8_t command;
    skt.recvall(&command, sizeof(command));
    return command;
}


void Protocol::moveQuery(int idunity, coordenada_t dest) {
    uint16_t id = htons(idunity);
    uint16_t desX = htons(dest.first);
    uint16_t desY = htons(dest.second); //castear???
    uint8_t command = SEARCH_PATH;

    skt.sendall(&command, sizeof(command));
    skt.sendall(&id, sizeof(id));
    skt.sendall(&desX, sizeof(desX));
    skt.sendall(&desY, sizeof(desY));
}

void Protocol::createBuilding(int clientId, int buildingId, coordenada_t coord) {
    uint16_t clientID = htons(clientId);
    uint16_t buildingID = htons(buildingId);
    uint16_t coordX = htons(coord.first);
    uint16_t coordY = htons(coord.second); //castear???
    uint8_t command = CREATE_BUILDING;

    skt.sendall(&command, sizeof(command));
    skt.sendall(&clientID, sizeof(clientID));
    skt.sendall(&buildingID, sizeof(buildingID));
    skt.sendall(&coordX, sizeof(coordX));
    skt.sendall(&coordY, sizeof(coordY));
}

