#ifndef AIRTRAP_H_
#define AIRTRAP_H_

#include "Building.h"

class AirTrap : public Building {
public:
    AirTrap(int id, coordenada_t coord);

    std::shared_ptr<Building> copy() override;
};

#endif // AIRTRAP_H_
