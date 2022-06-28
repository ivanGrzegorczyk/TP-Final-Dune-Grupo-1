#ifndef BARRACKS_H_
#define BARRACKS_H_

#include "Building.h"

class Barracks : public Building {
public:
    Barracks(int id, coordenada_t coord);

    std::shared_ptr<Building> copy() override;
};

#endif  // BARRACKS_H_
