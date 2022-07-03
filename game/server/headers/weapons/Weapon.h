#ifndef WEAPON_H_
#define WEAPON_H_

#include <memory>
class Unit;
#include "server/headers/units/Unit.h"
#include "common/headers/Chronometer.h"

class Weapon {
protected:
    unsigned int damage;
    unsigned int frecuency;
    Chronometer chronometer;

public:
    Weapon(unsigned int damage, unsigned int frequency);

    virtual bool attack(std::shared_ptr<Unit> &enemy) = 0;

    virtual ~Weapon() = default;
};


#endif  // WEAPON_H_
