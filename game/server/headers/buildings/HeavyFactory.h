#ifndef HEAVYFACTORY_H_
#define HEAVYFACTORY_H_

#include "Building.h"

class HeavyFactory : public Building {
public:
    HeavyFactory(int id, coordenada_t coord);

    std::shared_ptr<Building> copy() override;
};

#endif  // HEAVYFACTORY_H_
