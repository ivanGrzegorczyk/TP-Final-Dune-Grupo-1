#ifndef TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#define TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#include <cstdint>
#include <netinet/in.h>
#include <utility>
#include <vector>
#include <string>
#include "../../common/headers/Socket.h"
#include "../../common/headers/Constantes.h"
#include "Response.h"


class Protocol {
private:
    int id;
    Socket skt;
    void _fillVector(std::vector<uint8_t> &vector, int x, int y);

public:
    Protocol(std::string hostname, std::string servicename);
    int commandReceive();
    void moveQuery(int idunity ,coordenada_t dest);
    void createBuilding(int clientId, int buildingId, coordenada_t coord);

    int receiveId();

    void createUnidadLigera(int id);

    Response *recvResponse();

    void send(int command, std::vector<uint16_t> vector);

    std::pair<coordenada_t, std::vector<uint8_t>> receiveTerrain();
};


#endif //TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
