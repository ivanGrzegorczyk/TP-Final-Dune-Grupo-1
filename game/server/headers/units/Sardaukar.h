#ifndef SARDAUKAR_H_
#define SARDAUKAR_H_

#include "Unit.h"

class Sardaukar : public Unit {
public:
    Sardaukar(int id, coordenada_t coord);

    Sardaukar(int id, coordenada_t coord, bool attacking);

    std::shared_ptr<Unit> copy() override;
};

#endif  // SARDAUKAR_H_
