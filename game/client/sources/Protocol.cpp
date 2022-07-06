#include <stack>
#include "../headers/Protocol.h"
#include "client/headers/UpdateUnit.h"
#include "client/headers/UpdateBuilding.h"
#include "client/headers/UpdateVehicle.h"
#include "client/headers/UpdateTerrain.h"

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

void Protocol::send(int command, const std::vector<uint16_t>& vector) {
    uint16_t aux;
    uint8_t cmd = command;
    skt.sendall(&cmd, sizeof(cmd));
    for(uint16_t data : vector) {
        std::cout << "data en protocol: " << data << std::endl;

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
    uint16_t players, idPlayer;
    skt.recvall(&players, sizeof(players));
    players = ntohs(players);
    if(players == 0) {
        return nullptr;
    }
    auto* response = new Response();
    for(int p = 0; p < players ; p++) {
        skt.recvall(&idPlayer, sizeof(idPlayer));
        uint16_t money16;
        skt.recvall(&money16, sizeof(money16));

        idPlayer = ntohs(idPlayer);
        money = ntohs(money16);

         for(int e = 0; e < EVENTS; e++) {
             this->deserializeEvents(idPlayer, response, money);
         }
    }
    return response;
}

int Protocol::getMoney() {
    return money;
}

/*
React to responses sent by the server
*/
void Protocol::createResponse(uint8_t &eventType, int player, Response* response) {
    Event *event = nullptr;
    int entityType; int entityId;
    int posX; int posY;
    uint16_t amount;
    if(eventType == UNIT || eventType == BUILDING || eventType == VEHICLE) {
        this->receiveEntityInfo(entityType, entityId, posX, posY);
        coordenada_t coord({posX, posY});
        if(eventType == UNIT) {
            uint8_t att;
            uint16_t idTarget;
            skt.recvall(&att, sizeof(att));
            skt.recvall(&idTarget, sizeof(idTarget));

            event = new UpdateUnit(player, entityType, entityId, coord);
        }
        if(eventType == BUILDING) {
            event = new UpdateBuilding(player, entityType, entityId, coord);
        }
        if(eventType == VEHICLE) {
                event = new UpdateVehicle(player ,entityType, entityId, coord);
        }
    } else {
        std::invalid_argument("unrecognized argument");
    }
    if(event != nullptr) response->add(event);
}

void Protocol::deserializeEvents(uint16_t playerId, Response* response, uint16_t money) {
    uint8_t eventType;
    uint16_t amount;

    skt.recvall(&eventType, sizeof(eventType));

    if (eventType == SPICE) {
        skt.recvall(&amount, sizeof(amount));
        amount = ntohs(amount);
        for (int i = 0; i < amount; i++) {
            uint16_t position_x;
            uint16_t position_y;
            uint8_t soil;

            skt.recvall(&position_x, sizeof(position_x));
            skt.recvall(&position_y, sizeof(position_y));
            skt.recvall(&soil, sizeof(soil));

            position_x = ntohs(position_x);
            position_y = ntohs(position_y);
            response->add(new UpdateTerrain(playerId, position_x, position_y, soil));
        }
    } else {
        skt.recvall(&amount, sizeof(amount));
        amount = ntohs(amount);

        for(int j = 0; j < amount; j++) {
            this->createResponse(eventType, playerId, response);
        }
    }
}

/*
    Get type, entityId, and coordinates of an entity from the network
*/
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