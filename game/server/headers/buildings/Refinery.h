#ifndef REFINERY_H_
#define REFINERY_H_

#include "Building.h"

class Refinery : public Building {
private:
    unsigned int capacity;
    unsigned int spice;

public:
    Refinery(int id, coordenada_t coord);

    Refinery(int id, unsigned int spice, coordenada_t coord);

    std::shared_ptr<Building> copy() override;

    unsigned int getSpice() const;
};

#endif  // REFINERY_H_
