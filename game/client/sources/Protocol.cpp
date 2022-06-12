#include <stack>
#include "../headers/Protocol.h"

Protocol::Protocol(const char* hostname, const char* servicename) : skt(hostname, servicename){
}

void Protocol::_serializeAndSend(int currentX, int currentY, int dstX, int dstY) {
    uint8_t command = SEARCH_PATH;
    uint16_t currtX = htons((uint16_t)currentX);
    uint16_t currtY = htons((uint16_t)currentY);
    uint16_t desX = htons((uint16_t)dstX);
    uint16_t desY = htons((uint16_t)dstY);

    skt.sendall(&command, sizeof(command));
    skt.sendall(&currtX, sizeof(currtX));
    skt.sendall(&desX, sizeof(desX));
    skt.sendall(&desY, sizeof(desY));
}

void Protocol::sendUbication(std::pair<coordenada_t, coordenada_t> ubication) {
    int currentX = ubication.first.first;
    int currentY = ubication.first.second;
    int dstX = ubication.second.first;
    int dstY = ubication.second.second;
    _serializeAndSend(currentX, currentY, dstX, dstY);
}

/*std::vector<coordenada_t> Protocol::receivePath() {
    std::vector<coordenada_t> path;
    uint8_t length;
    skt.recvall(&length, sizeof(length));

    path.resize(int(length));
    for (int i = 0; i < int(length); i++) {
        _fillVector(path);
    }
    return path;
}*/

void Protocol::_fillVector(std::vector<coordenada_t> &v) {
    uint16_t posX;
    uint16_t posY;
    skt.recvall(&posX, sizeof(posX));
    coordenada_t coord {(int) ntohs(posX), (int) ntohs(posY)};
    v.push_back(coord);
}

void Protocol::enviar(std::vector<uint16_t> vector) {

    //evento.get
    uint8_t comando = SEARCH_PATH;
    skt.sendall(&comando, sizeof(comando));
    for (uint16_t coord : vector) {
        uint16_t aux;
        aux = htons(coord);
        skt.sendall(&aux, sizeof(aux));
    }
}

int Protocol::commandReceive() {
    uint8_t command;
    skt.recvall(&command, sizeof(command));
    return command;
}

std::stack<coordenada_t> Protocol::receivePath() {
    uint16_t largo;
    std::stack<coordenada_t> path;
    skt.recvall(&largo, sizeof(largo));
    largo = ntohs(largo);
    for(int i = 0; i < largo / 2; i++) {
        uint16_t x;
        uint16_t y;
        skt.recvall(&x, sizeof(x));
        x = ntohs(x);
        skt.recvall(&y, sizeof(y));
        y = ntohs(y);
        path.push(coordenada_t {x, y});
    }
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


