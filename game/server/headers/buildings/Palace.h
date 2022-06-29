#ifndef PALACE_H_
#define PALACE_H_

#include "Building.h"

class Palace : public Building {
public:
    Palace(int id, coordenada_t coord);

    std::shared_ptr<Building> copy() override;
};

#endif  // PALACE_H_
