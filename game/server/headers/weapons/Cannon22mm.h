#ifndef CANNON22MM_H_
#define CANNON22MM_H_

#include "server/headers/units/Unit.h"

class Cannon22mm : public Weapon {
public:
    Cannon22mm();
    ~Cannon22mm() override = default;

    bool attack(std::shared_ptr<Unit> &enemy, bool &attacked) override;
};

#endif  // CANNON22MM_H_
