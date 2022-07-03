#include "server/headers/weapons/MissileLauncher.h"

MissileLauncher::MissileLauncher() : Weapon(MISSILE_LAUNCHER_DAMAGE, MISSILE_LAUNCHER_FREQUENCY) {}

bool MissileLauncher::attack(std::shared_ptr<Unit> &enemy, bool &attacked) {
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
