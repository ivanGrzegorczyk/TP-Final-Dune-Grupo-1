#ifndef TP_FINAL_DUNE_GRUPO_1_CREATELIGHTINFANTRY_H
#define TP_FINAL_DUNE_GRUPO_1_CREATELIGHTINFANTRY_H
#include "../../common/headers/Constantes.h"
#include "Request.h"


class CreateLightInfantry : public Request{
private:
    int unitId;
    coordenada_t coord;
public:
    CreateLightInfantry(int x, int y);
    std::vector<uint16_t> getData() override;
    int getCommand() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATELIGHTINFANTRY_H
