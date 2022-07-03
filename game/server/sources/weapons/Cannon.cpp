#include "server/headers/weapons/Cannon.h"

Cannon::Cannon() : Weapon(CANNON_DAMAGE, CANNON_FREQUENCY) {}

bool Cannon::attack(std::shared_ptr<Unit> &enemy) {
    bool killed = false;

    if (chronometer.tack() >= frecuency) {
        killed = enemy->receiveDamage(damage);
        chronometer.tick();
    }

    return killed;
}
