#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEUNIDADLIGERA_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEUNIDADLIGERA_H
#include "../../common/headers/Constantes.h"
#include "Request.h"


class CreateUnidadLigera : public Request{
private:
    int unityId;
public:
    CreateUnidadLigera();
    std::vector<uint16_t> getData() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEUNIDADLIGERA_H
