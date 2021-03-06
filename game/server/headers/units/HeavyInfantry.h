#ifndef HEAVYINFANTRY_H_
#define HEAVYINFANTRY_H_

#include "Unit.h"

class HeavyInfantry : public Unit {
public:
    HeavyInfantry(int id, coordenada_t coord);

    HeavyInfantry(int id, coordenada_t coord, bool attacking);

    std::shared_ptr<Unit> copy() override;
};

#endif  // HEAVYINFANTRY_H_
