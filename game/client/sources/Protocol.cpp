#include <stack>
#include "../headers/Protocol.h"

Protocol::Protocol(std::string hostname, std::string servicename) : id(-1), skt(hostname.c_str(), servicename.c_str()){
}

int Protocol::receiveId() {
    uint16_t id;
    int idHost;
    skt.recvall(&id, sizeof(id));

    //this->id = ntohs(idProtocol);
    //this->id = 1; //TODO sacar el hardcodeo
    std::cout << "ID RECIBIDO: " << unsigned(ntohs(id))<< std::endl;
    idHost = ntohs(id);
    return idHost;
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
    //while(i < lengthResponse) {
        skt.recvall(&idPlayer, sizeof(idPlayer));
        skt.recvall(&action, sizeof(action));
        skt.recvall(&characterId, sizeof(characterId));
        skt.recvall(&posX, sizeof(posX));
        skt.recvall(&posY, sizeof(posY));
        coordenada_t coord = {ntohs(posX), ntohs(posY)};
        //int idP = ntohs(idPlayer);
        response->add(1, 1, coord); //TODO sacar el hardcodeo
      //  i += 5;
        //response->addResponseChunk(ntohs(chunk));
    //}
    return response;
}

void Protocol::send(int command, std::vector<uint16_t> vector) {
    uint16_t aux;
    uint8_t cmd = command;
    skt.sendall(&cmd, sizeof(cmd));
    for(uint16_t data : vector) {
        std::cout << "data: " << unsigned(data) << std::endl;
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


