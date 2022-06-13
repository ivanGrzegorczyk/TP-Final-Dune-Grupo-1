#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEUNIDADLIGERA_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEUNIDADLIGERA_H
#include "../../common/headers/Constantes.h"
#include "Request.h"

class CreateUnidadLigera : public Request{
private:
    int unityId;
public:
    CreateUnidadLigera();
    void send(Protocol &protocol) override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEUNIDADLIGERA_H
