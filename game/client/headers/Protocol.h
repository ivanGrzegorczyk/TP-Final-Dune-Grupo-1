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
#include "Response.h"


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

    Response* recvResponse();

    void send(int command, const std::vector<uint16_t>& vector);

    std::pair<coordenada_t, std::vector<uint8_t>> receiveTerrain();

    void createResponse(uint8_t &eventType, int player, Response *response);

    void receiveEntityInfo(int &entityType, int &entityId, int &coordX, int &coordY);
    void shutdown();
    void close();

    void deserializeEvents(uint16_t playerId, Response *response, uint16_t money);
};


#endif //TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
