#ifndef MISSILELAUNCHER_H_
#define MISSILELAUNCHER_H_

#include <memory>
#include "server/headers/units/Unit.h"

class MissileLauncher : public Weapon {
public:
    MissileLauncher();
    ~MissileLauncher() override = default;

    bool attack(std::shared_ptr<Unit> &enemy, bool &attacked) override;
};


#endif  // MISSILELAUNCHER_H_
