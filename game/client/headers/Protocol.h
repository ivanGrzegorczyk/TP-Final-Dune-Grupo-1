#ifndef TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#define TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#include <cstdint>
#include <netinet/in.h>
#include <utility>
#include <vector>
#include <string>
#include "../../common/headers/Socket.h"
#include "../../common/headers/Constantes.h"
#include "common/headers/ProtectedQueue.h"
class Response;


class Protocol {
private:
    int id;
    Socket skt;
    void _fillVector(std::vector<uint8_t> &vector, int x, int y);

public:
    Protocol(const std::string& hostname, const std::string& servicename);
    int commandReceive();
    void moveQuery(int idunity ,coordenada_t dest);
    void createBuilding(int clientId, int buildingId, coordenada_t coord);

    int receiveId();

    void createUnidadLigera(int id);

    std::vector<Response*> recvResponse();

    void send(int command, const std::vector<uint16_t>& vector);

    std::pair<coordenada_t, std::vector<uint8_t>> receiveTerrain();

    void createResponse(uint16_t &eventType, int player, std::vector<Response *> &vector);
};


#endif //TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
