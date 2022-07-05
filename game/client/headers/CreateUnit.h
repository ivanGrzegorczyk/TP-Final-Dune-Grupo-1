#ifndef TP_FINAL_DUNE_GRUPO_1_CREATELIGHTINFANTRY_H
#define TP_FINAL_DUNE_GRUPO_1_CREATELIGHTINFANTRY_H
#include "../../common/headers/Constantes.h"
#include "Request.h"


class CreateUnit : public Request {
private:
    int unit;
    coordenada_t coord;
public:
    CreateUnit(int x, int y, int unit);
    std::vector<uint16_t> getData() override;
    int getCommand() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATELIGHTINFANTRY_H
