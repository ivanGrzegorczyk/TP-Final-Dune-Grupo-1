#ifndef TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#define TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
#include <cstdint>
#include <netinet/in.h>
#include <utility>
#include <vector>
#define SEARCH_PATH 1

typedef std::pair<int, int> coordenada_t;

class Protocol {
private:
    //Socket skt;
    void _fillVector(std::vector<coordenada_t> &v);
    void _serializeAndSend(int currentX, int currentY, int dstX, int dstY);
public:
    Protocol();
    void sendUbication(std::pair<coordenada_t, coordenada_t> ubication);
    std::vector<coordenada_t> receivePath();

};


#endif //TP_FINAL_DUNE_GRUPO_1_PROTOCOL_H
