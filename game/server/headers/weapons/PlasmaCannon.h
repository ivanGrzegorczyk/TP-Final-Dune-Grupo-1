#ifndef PLASMACANNON_H_
#define PLASMACANNON_H_

#include "Weapon.h"

class PlasmaCannon : public Weapon {
public:
    PlasmaCannon();
    ~PlasmaCannon() override = default;

    bool attack(std::shared_ptr<Unit> &enemy) override;
};

#endif  // PLASMACANNON_H_
