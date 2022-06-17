#ifndef CHRONOMETER_H_
#define CHRONOMETER_H_

#include <chrono>
#include <ostream>

#define CHRONO_PRECISION 2
#define CHRONO_UNIT "us"

class Chronometer {
public:
    Chronometer();
    ~Chronometer() = default;
    /**
     * Devuelve el tiempo parcial desde que se construyó el chronómetro
     * @return tiempo en milisegundos
     */
    double tick();
private:
    std::chrono::high_resolution_clock::time_point start;
};

/**
 * Imprime el tiempo formateado en el flujo de salida que se le pase
 * @param os
 * @return
 */
std::ostream& operator<<(std::ostream &os, Chronometer &chrono);

#endif  // CHRONOMETER_H_
