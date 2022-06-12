#ifndef TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#define TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#include <cstdint>
#include <netinet/in.h>
#include <utility>
#include <vector>
#include "../../common/headers/Socket.h"

#define SEARCH_PATH 1

typedef std::pair<int, int> coordenada_t;

class Protocol {
private:
    Socket skt;
    void _fillVector(std::vector<coordenada_t> &v);
    void _serializeAndSend(int currentX, int currentY, int dstX, int dstY);
public:
    Protocol(const char* hostname, const char* servicename);
    void sendUbication(std::pair<coordenada_t, coordenada_t> ubication);
    //std::vector<coordenada_t> receivePath();



    void enviar(std::vector<uint16_t> vector);

    int commandReceive();
    std::stack<coordenada_t> receivePath();

    void moveQuery(int idunity ,coordenada_t dest);
};


#endif //TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
