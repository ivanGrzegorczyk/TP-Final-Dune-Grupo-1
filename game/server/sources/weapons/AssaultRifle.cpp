#include "server/headers/weapons/AssaultRifle.h"
#include "common/headers/Constantes.h"

AssaultRifle::AssaultRifle() :
        Weapon(ASSAULT_RIFLE_DAMAGE, ASSAULT_RIFLE_FREQUENCY) {}

bool AssaultRifle::attack(std::shared_ptr<Unit> &enemy, bool &attacked) {
    bool killed = false;

    if (chronometer.tack() >= frecuency) {
        attacked = true;
        if (enemy->getType() == UNIT_LIGHT_INFANTRY || enemy->getType() == UNIT_HEAVY_INFANTRY)
            killed = enemy->receiveDamage(damage + 1);
        else
            killed = enemy->receiveDamage(damage);
        chronometer.tick();
    } else {
        attacked = false;
    }

    return killed;
}
