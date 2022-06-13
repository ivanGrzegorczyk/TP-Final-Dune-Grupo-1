#ifndef TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#define TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#include <cstdint>
#include <netinet/in.h>
#include <utility>
#include <vector>
#include "../../common/headers/Socket.h"

#define SEARCH_PATH 1
#define CREATE_BUILDING 2

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
};


#endif //TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
