#ifndef SOUNDWAVE_H_
#define SOUNDWAVE_H_

#include "Weapon.h"

class SoundWave : Weapon {
public:
    SoundWave();
    ~SoundWave() override = default;

    bool attack(std::shared_ptr<Unit> &enemy, bool &attacked) override;
};

#endif  // SOUNDWAVE_H_
