#ifndef PLAYER_H_
#define PLAYER_H_

#include <memory>
#include <map>
#include "../../common/headers/Unit.h"
#include "../../common/headers/Building.h"

class Player {
private:
    int id;
    int house;
    int money;
    std::map<int, std::shared_ptr<Unit>> units;
    std::map<int, std::shared_ptr<Building>> buildings;

public:
    Player(int id, int house);
};

#endif  // PLAYER_H_
