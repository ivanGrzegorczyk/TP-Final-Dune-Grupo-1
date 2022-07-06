#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEHEAVYINFANTRY_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEHEAVYINFANTRY_H

#include "client/headers/Request.h"
#include "common/headers/Constantes.h"

class CreateHeavyInfantry : public Request {
private:
    coordenada_t coord;
public:
    CreateHeavyInfantry(int x, int y);
    std::vector<uint16_t> getData() override;
    int getCommand() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEHEAVYINFANTRY_H
