#ifndef TP_FINAL_DUNE_GRUPO_1_ATTACKREQUEST_H
#define TP_FINAL_DUNE_GRUPO_1_ATTACKREQUEST_H

#include "common/headers/Constantes.h"
#include "Request.h"

class AttackRequest : public Request {
private:
    int attackerId;
    int enemyId;
public:
    AttackRequest(int attackerId, int enemyId);
    int getCommand() override;
    std::vector<uint16_t> getData() override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_ATTACKREQUEST_H
