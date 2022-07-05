#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEHARVESTER_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEHARVESTER_H


#include "Request.h"
#include "common/headers/Constantes.h"

class CreateHarvester : public Request {
private:
    coordenada_t coord;
public:
    CreateHarvester(int x, int y);
    std::vector<uint16_t> getData() override;
    int getCommand() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEHARVESTER_H
