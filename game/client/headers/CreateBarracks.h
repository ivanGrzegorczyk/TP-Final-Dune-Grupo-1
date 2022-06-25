#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H


#include "../headers/Request.h"
#include "../../common/headers/Constantes.h"

class CreateBuilding : public Request{
private:
    coordenada_t coord;
public:
    CreateBuilding(int x, int y);
    std::vector<uint16_t> getData() override;
    int getCommand() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H
