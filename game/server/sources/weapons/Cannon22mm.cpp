#include "server/headers/weapons/Cannon22mm.h"

Cannon22mm::Cannon22mm() : Weapon(CANNON22MM_DAMAGE, CANNON22MM_FREQUENCY) {}

bool Cannon22mm::attack(std::shared_ptr<Unit> &enemy) {
    bool killed = false;

    if (chronometer.tack() >= frecuency) {
        killed = enemy->receiveDamage(damage);
        chronometer.tick();
    }

    return killed;
}
