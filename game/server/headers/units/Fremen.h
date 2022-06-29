#ifndef FREMEN_H_
#define FREMEN_H_

#include "Unit.h"

class Fremen : public Unit {
public:
    Fremen(int id, coordenada_t coord);
    std::shared_ptr<Unit> copy() override;
};

#endif  // FREMEN_H_
