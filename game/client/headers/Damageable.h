#ifndef TP_FINAL_DUNE_GRUPO_1_DAMAGEABLE_H
#define TP_FINAL_DUNE_GRUPO_1_DAMAGEABLE_H
#include "SDL2pp/SDL2pp.hh"

class Damageable {
public:
    virtual void takeDamage(int damage) = 0;
};

#endif //TP_FINAL_DUNE_GRUPO_1_DAMAGEABLE_H
