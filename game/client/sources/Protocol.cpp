#include "../headers/Protocol.h"

Protocol::Protocol() {
}

//formato sendUbicacion: tipoComando(1 byte), coordenadas(2bytes BE)
void Protocol::_serializeAndSend(int currentX, int currentY, int dstX, int dstY) {
    uint8_t command = SEARCH_PATH;
    uint16_t currtX = htons((uint16_t)currentX);
    uint16_t currtY = htons((uint16_t)currentY);
    uint16_t desX = htons((uint16_t)dstX);
    uint16_t desY = htons((uint16_t)dstY);

    /*skt.sendAll(&command, sizeof(command), );
    skt.sendAll(&currtX, sizeof(currtX), );
    skt.sendAll(&desX, sizeof(desX));
    skt.sendAll(&desY, sizeof(desY));*/
}

void Protocol::sendUbication(std::pair<coordenada_t, coordenada_t> ubication) {
    int currentX = ubication.first.first;
    int currentY = ubication.first.second;
    int dstX = ubication.second.first;
    int dstY = ubication.second.second;
    _serializeAndSend(currentX, currentY, dstX, dstY);
}

std::vector<coordenada_t> Protocol::receivePath() {
    std::vector<coordenada_t> path;
    uint8_t length;
    //skt.recvAll(&length, sizeof(length), );

    path.resize(int(length));
    for (int i = 0; i < int(length); i++) {
        _fillVector(path);
    }
    return path;
}

void Protocol::_fillVector(std::vector<coordenada_t> &v) {
    uint16_t posX;
    uint16_t posY;
    //skt.recvAll(&posX, sizeof(posX), );
    coordenada_t coord {(int) ntohs(posX), (int) ntohs(posY)};
    v.push_back(coord);
}
//formato manda longitud del vector de 1 byte