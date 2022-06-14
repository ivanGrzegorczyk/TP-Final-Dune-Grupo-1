#include "../headers/CreateUnidadLigera.h"

void CreateUnidadLigera::send(Protocol &protocol) {
    protocol.createUnidadLigera(this->unityId);
}

CreateUnidadLigera::CreateUnidadLigera() : unityId(UNIT_LIGHT_INFANTRY) {

}
