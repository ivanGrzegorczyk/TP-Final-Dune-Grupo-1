#ifndef ASSAULTRIFLE_H_
#define ASSAULTRIFLE_H_

#include "Weapon.h"

class AssaultRifle : public Weapon {
public:
    AssaultRifle();
    ~AssaultRifle() override = default;

    bool attack(std::shared_ptr<Unit> &enemy) override;
};

#endif  // ASSAULTRIFLE_H_
