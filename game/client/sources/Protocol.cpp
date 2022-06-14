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
    uint8_t command = REPOSITION_EVENT;

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
    uint8_t command = CREATE_BUILDING_EVENT;

    skt.sendall(&command, sizeof(command));
    skt.sendall(&clientID, sizeof(clientID));
    skt.sendall(&buildingID, sizeof(buildingID));
    skt.sendall(&coordX, sizeof(coordX));
    skt.sendall(&coordY, sizeof(coordY));
}

void Protocol::createUnidadLigera(int id) {
    uint8_t command = CREATE_UNIT_EVENT;
    uint8_t unityId = id;
    skt.sendall(&command, sizeof(command));
    skt.sendall((&unityId), sizeof(unityId));
}

Response* Protocol::recvResponse() {
    //std::map<int, std::map<int, std::shared_ptr<Building>>> buildings;
    //std::map<int, std::pair<int, coordenada_t>> units;
    int i = 0;
    uint16_t lengthResponse;
    skt.recvall(&lengthResponse, sizeof(lengthResponse));
    lengthResponse = ntohs(lengthResponse);
    auto* response = new Response();
    //uint16_t bytesPlayer;

    //uint16_t chunk;
    uint16_t idPlayer;
    uint16_t action;
    uint16_t characterId;
    uint16_t posX;
    uint16_t posY;
    while(i < lengthResponse) {
        skt.recvall(&idPlayer, sizeof(idPlayer));
        skt.recvall(&action, sizeof(action));
        skt.recvall(&characterId, sizeof(characterId));
        skt.recvall(&posX, sizeof(posX));
        skt.recvall(&posY, sizeof(posY));
        coordenada_t coord = {ntohs(posX), ntohs(posY)};
        response->add(idPlayer, characterId, coord);
        i += 5;
        //response->addResponseChunk(ntohs(chunk));
    }
    return response;
}

