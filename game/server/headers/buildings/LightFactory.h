#ifndef LIGHTFACTORY_H_
#define LIGHTFACTORY_H_

#include "Building.h"

class LightFactory : public Building {
public:
    LightFactory(int id, coordenada_t coord);

    std::shared_ptr<Building> copy() override;
};

#endif // LIGHTFACTORY_H_
