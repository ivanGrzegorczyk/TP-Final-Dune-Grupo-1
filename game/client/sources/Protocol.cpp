#include <stack>
#include "../headers/Protocol.h"
#include "client/headers/UpdateUnit.h"
#include "client/headers/UpdateBuilding.h"
#include "client/headers/UpdateVehicle.h"

Protocol::Protocol(const std::string& hostname, const std::string& servicename) :
        id(-1), skt(hostname.c_str(), servicename.c_str()){
}

int Protocol::receiveId() {
    uint16_t id;
    int idHost;
    skt.recvall(&id, sizeof(id));
    idHost = ntohs(id);
    return idHost;
}

void Protocol::shutdown() {
    skt.shutdown(SHUT_RDWR);
    skt.close();
}
int Protocol::commandReceive() {
    uint8_t command;
    skt.recvall(&command, sizeof(command));
    return command;
}


void Protocol::moveQuery(int idunity, coordenada_t dest) {
    uint16_t id = htons(idunity);
    uint16_t desX = htons(dest.first);
    uint16_t desY = htons(dest.second);
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
    uint16_t coordY = htons(coord.second);
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


void Protocol::send(int command, const std::vector<uint16_t>& vector) {
    uint16_t aux;
    uint8_t cmd = command;
    skt.sendall(&cmd, sizeof(cmd));
    for(uint16_t data : vector) {
        std::cout << "data: " << data << std::endl;

        aux = htons(data);
        skt.sendall(&aux, sizeof(aux));
    }
}

void Protocol::_fillVector(std::vector<uint8_t> &vector, int x, int y) {
    uint8_t terrainType;
    for(int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) {
            skt.recvall(&terrainType, sizeof (terrainType));
            vector.push_back(terrainType);
        }
    }
}

std::pair<coordenada_t, std::vector<uint8_t>> Protocol::receiveTerrain() {
    std::pair<coordenada_t ,std::vector<uint8_t>> terrain;
    uint16_t x;
    uint16_t y;
    int xHost;
    int yHost;

    skt.recvall(&x, sizeof(x));
    skt.recvall(&y, sizeof(y));
    xHost = ntohs(x);
    yHost = ntohs(y);
    terrain.first.first = xHost;
    terrain.first.second = yHost;
    _fillVector(terrain.second, xHost, yHost);
    return terrain;
}

Response* Protocol::recvResponse() {
    uint16_t players; uint16_t idPlayer;
    skt.recvall(&players, sizeof(players));
    players = ntohs(players);
    if(players == 0) {
        return nullptr;
    }
    auto* response = new Response();
    for(int p = 0; p < players ; p++) {
        skt.recvall(&idPlayer, sizeof(idPlayer));
         for(int e = 0; e < EVENTS; e++) {
             this->deserializeEvents(idPlayer, response);
         }
    }
    return response;
}

/*
React to responses sent by the server
*/
void Protocol::createResponse(uint8_t &eventType, int player, Response* response) {
    Event *event;
    int entityType; int entityId;
    int posX; int posY;
    this->receiveEntityInfo(entityType, entityId, posX, posY);
    coordenada_t coord({posX * (LENGTH_TILE/8), posY * (LENGTH_TILE/8)});
    if(eventType == UNIT) {
        event = new UpdateUnit(player, entityType, entityId, coord);
            //break;
    }
    if(eventType == BUILDING) {
        event = new UpdateBuilding(player, entityType, entityId, coord);
            //break;
    }
    if(eventType == VEHICLE) {
            event = new UpdateVehicle(player ,entityType, entityId, coord);
    }
    response->add(event);
}

void Protocol::deserializeEvents(uint16_t playerId, Response* response) {
    uint8_t eventType;
    uint16_t amount;

    skt.recvall(&eventType, sizeof(eventType));
    skt.recvall(&amount, sizeof(amount));
    playerId = ntohs(playerId);
    amount = ntohs(amount);

    for(int j = 0; j < amount; j++) {
        this->createResponse(eventType, playerId, response);
    }
}


void Protocol::receiveEntityInfo(int &entityType, int &entityId, int &coordX, int &coordY) {
    uint8_t type; uint16_t idEntity;
    uint16_t posX; uint16_t posY;

    skt.recvall(&type, sizeof(type));
    skt.recvall(&idEntity, sizeof(idEntity));
    skt.recvall(&posX, sizeof(posX));
    skt.recvall(&posY, sizeof(posY));

    entityType = type;
    entityId = (int)ntohs(idEntity);
    coordX = (int)ntohs(posX);
    coordY = (int)ntohs(posY);
}

void Protocol::close() {
    this->skt.shutdown(SHUT_RDWR);
    this->skt.close();
}