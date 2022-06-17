#ifndef TP_FINAL_DUNE_GRUPO_1_MOVEQUERY_H
#define TP_FINAL_DUNE_GRUPO_1_MOVEQUERY_H
#include "Request.h"
#include "../../common/headers/Constantes.h"


class MoveQuery : public Request {
private:
    int unityId;
    coordenada_t dest;
public:
    explicit MoveQuery(int id, coordenada_t &&dst);
    std::vector<uint16_t> getData() override;
    int getCommand() override;
};

#endif //TP_FINAL_DUNE_GRUPO_1_MOVEQUERY_H
