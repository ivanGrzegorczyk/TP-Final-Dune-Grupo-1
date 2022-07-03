#include "client/headers/AttackRequest.h"

AttackRequest::AttackRequest(int attackerId, int enemyId) : attackerId(attackerId), enemyId(enemyId) {
}

int AttackRequest::getCommand() {
    return ATTACKING_EVENT;
}

std::vector<uint16_t> AttackRequest::getData() {
    std::vector<uint16_t> data(2, 0);
    data[0] = attackerId;
    data[1] = enemyId;
    return data;
}
