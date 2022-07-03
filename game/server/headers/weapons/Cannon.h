#ifndef CANNON_H_
#define CANNON_H_

#include "Weapon.h"

class Cannon : public Weapon {
public:
    Cannon();
    ~Cannon() override = default;

    bool attack(std::shared_ptr<Unit> &enemy) override;
};

#endif  // CANNON_H_
