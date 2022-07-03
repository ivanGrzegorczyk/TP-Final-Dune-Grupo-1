#ifndef LIGHTINFANTRY_H_
#define LIGHTINFANTRY_H_

#include "Unit.h"

class LightInfantry : public Unit {
public:
    LightInfantry(int id, coordenada_t coord);
    LightInfantry(int id, coordenada_t coord, bool attacking);
    ~LightInfantry() override = default;

    std::shared_ptr<Unit> copy() override;
};

#endif  // LIGHTINFANTRY_H_
