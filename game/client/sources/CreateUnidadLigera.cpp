#include "../headers/CreateUnidadLigera.h"

void CreateUnidadLigera::send(Protocol &protocol) {
    protocol.createUnidadLigera(this->unityId);
}

CreateUnidadLigera::CreateUnidadLigera() : unityId(LIGHT_INFANTRY) {

}
