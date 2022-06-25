#include "common/headers/Chronometer.h"

using _clock = std::chrono::system_clock;

Chronometer::Chronometer(): start(_clock::now()) {}

void Chronometer::tick() {
    start = _clock::now();
}

uint64_t Chronometer::tack() {
    auto current = _clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(current - this->start);
    return diff.count();
}
