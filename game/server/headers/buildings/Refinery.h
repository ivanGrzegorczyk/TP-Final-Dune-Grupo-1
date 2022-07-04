#ifndef REFINERY_H_
#define REFINERY_H_

#include "Building.h"
#include "common/headers/Chronometer.h"

#define UNLOAD_TIME 1000000  // Tiempo que tarda en descargar MAX_UNLOADED
#define MAX_UNLOADED 40

class Refinery : public Building {
private:
    int capacity;
    int spice;
    Chronometer chronometer;

public:
    Refinery(int id, coordenada_t coord);

    Refinery(int id, unsigned int spice, coordenada_t coord);

    std::shared_ptr<Building> copy() override;

    int getSpice() const;

    bool isFull() const;

    // Retorna el excedente
    unsigned int load(int &harvesterSpice);

    int getCapacity() const;
};

#endif  // REFINERY_H_
