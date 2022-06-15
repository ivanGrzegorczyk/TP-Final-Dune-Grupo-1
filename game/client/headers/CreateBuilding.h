#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H


#include "../headers/Request.h"
#include "../../common/headers/Constantes.h"

class CreateBuilding : public Request{
private:
    int idClient;
    int idBuilding;
    coordenada_t coord;
public:
    CreateBuilding(int idClient, int idBuilding, coordenada_t &&coord);
    std::vector<uint16_t> getData() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H
