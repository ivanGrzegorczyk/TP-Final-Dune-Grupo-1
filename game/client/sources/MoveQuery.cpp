#include "../headers/MoveQuery.h"

MoveQuery::MoveQuery(int id, coordenada_t &&dst) : unityId(id) , dest(dst){

}

void MoveQuery::send(Protocol &protocol) {
    protocol.moveQuery(unityId , dest);
}

