#ifndef SILO_H_
#define SILO_H_

#include "Building.h"

class Silo : public Building {
private:
    unsigned int capacity;
    unsigned int spice;

public:
    Silo(int id, coordenada_t coord);

    Silo(int id, unsigned int spice, coordenada_t coord);

    std::shared_ptr<Building> copy() override;

    unsigned int getSpice() const;
};

#endif  // SILO_H_
