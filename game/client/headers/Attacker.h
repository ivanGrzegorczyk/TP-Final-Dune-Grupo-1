#ifndef TP_FINAL_DUNE_GRUPO_1_ATTACKER_H
#define TP_FINAL_DUNE_GRUPO_1_ATTACKER_H
#include "client/headers/Damageable.h"
#include "SDL2pp/SDL2pp.hh"

class Attacker {
public:
    virtual void attack(Damageable* d, int damage) = 0;
};

#endif //TP_FINAL_DUNE_GRUPO_1_ATTACKER_H
