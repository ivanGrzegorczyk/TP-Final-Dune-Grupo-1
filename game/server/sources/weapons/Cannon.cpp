#include "server/headers/weapons/Cannon.h"

Cannon::Cannon() : Weapon(CANNON_DAMAGE, CANNON_FREQUENCY) {}

bool Cannon::attack(std::shared_ptr<Unit> &enemy, bool &attacked) {
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
