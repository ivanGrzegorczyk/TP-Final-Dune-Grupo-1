#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEBARRACKS_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEBARRACKS_H


#include "../headers/Request.h"
#include "../../common/headers/Constantes.h"

class CreateBarracks : public Request{
private:
    coordenada_t coord;
public:
    CreateBarracks(int x, int y);
    std::vector<uint16_t> getData() override;
    int getCommand() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEBARRACKS_H
