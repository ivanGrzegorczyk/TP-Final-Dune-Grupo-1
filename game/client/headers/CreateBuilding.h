#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEBARRACKS_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEBARRACKS_H


#include "../headers/Request.h"
#include "../../common/headers/Constantes.h"

class CreateBuilding : public Request{
private:
    coordenada_t coord;
    int typeId;
public:
    CreateBuilding(int x, int y, int typeId);
    std::vector<uint16_t> getData() override;
    int getCommand() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEBARRACKS_H
