#include "server/headers/weapons/PlasmaCannon.h"

PlasmaCannon::PlasmaCannon() : Weapon(PLASMA_CANNON_DAMAGE, PLASMA_CANNON_FREQUENCY) {}

bool PlasmaCannon::attack(std::shared_ptr<Unit> &enemy) {
    bool killed = false;

    if (chronometer.tack() >= frecuency) {
        killed = enemy->receiveDamage(damage);
        chronometer.tick();
    }

    return killed;
}
