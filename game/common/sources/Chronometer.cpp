#include <iomanip>
#include "../headers/Chronometer.h"

Chronometer::Chronometer(): start(std::chrono::high_resolution_clock::now()) {}

double Chronometer::tick() {
    auto current = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(current - this->start)
            .count();
}

std::ostream &operator<<(std::ostream &os, Chronometer &chrono) {
    os << std::fixed << std::setprecision(CHRONO_PRECISION) << chrono.tick()
       << CHRONO_UNIT;
    return os;
}
