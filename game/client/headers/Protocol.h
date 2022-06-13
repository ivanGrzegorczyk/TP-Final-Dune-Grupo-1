#ifndef TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#define TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#include <cstdint>
#include <netinet/in.h>
#include <utility>
#include <vector>
#include "../../common/headers/Constantes.h"
#include "../../common/headers/Socket.h"


typedef std::pair<int, int> coordenada_t;

class Protocol {
private:
    int id;
    Socket skt;

public:
    Protocol(const char* hostname, const char* servicename);
    int commandReceive();
    void moveQuery(int idunity ,coordenada_t dest);
    void createBuilding(int clientId, int buildingId, coordenada_t coord);

    void receiveId();

    int getId() const;

    void createUnidadLigera(int id);
};


#endif //TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
