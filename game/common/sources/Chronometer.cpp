#include "common/headers/Chronometer.h"

Chronometer::Chronometer(): start(_clock::now()) {}

uint64_t Chronometer::tick() {
    auto current = _clock::now();
    return _duration(current - this->start).count();
}
