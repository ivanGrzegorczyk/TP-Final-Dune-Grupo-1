#include "server/headers/weapons/MissileLauncher.h"

MissileLauncher::MissileLauncher() : Weapon(MISSILE_LAUNCHER_DAMAGE, MISSILE_LAUNCHER_FREQUENCY) {}

bool MissileLauncher::attack(std::shared_ptr<Unit> &enemy) {
    bool killed = false;

    if (chronometer.tack() >= frecuency) {
        killed = enemy->receiveDamage(damage);
        chronometer.tick();
    }

    return killed;
}
