#ifndef CONSTRUCTIONCENTER_H_
#define CONSTRUCTIONCENTER_H_

#include "Building.h"

class ConstructionCenter : public Building {
public:
    ConstructionCenter(int id, coordenada_t coord);

    std::shared_ptr<Building> copy() override;
};

#endif  // CONSTRUCTIONCENTER_H_
