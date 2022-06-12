#include "../headers/MoveQuery.h"

void MoveQuery::send(Protocol &protocol) {
    protocol.moveQuery(unityId , dest);
}

MoveQuery::MoveQuery(int id, coordenada_t &&dst) : unityId(id) , dest(dst){

}
