#include "server/headers/weapons/PlasmaCannon.h"

PlasmaCannon::PlasmaCannon() : Weapon(PLASMA_CANNON_DAMAGE, PLASMA_CANNON_FREQUENCY) {}

bool PlasmaCannon::attack(std::shared_ptr<Unit> &enemy, bool &attacked) {
    bool killed = false;

    if (chronometer.tack() >= frecuency) {
        attacked = true;
        killed = enemy->receiveDamage(damage);
        chronometer.tick();
    } else {
        attacked = false;
    }

    return killed;
}
