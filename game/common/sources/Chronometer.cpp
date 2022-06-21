#include "common/headers/Chronometer.h"

using _clock = std::chrono::system_clock;
using _duration = std::chrono::microseconds;

Chronometer::Chronometer(): start(_clock::now()) {}

uint64_t Chronometer::now() {
    auto current = _clock::now();
    _duration diff = std::chrono::duration_cast<_duration>(current - this->start);
    return diff.count();
}
