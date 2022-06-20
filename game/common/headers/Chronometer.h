#include <chrono>
#include <ostream>

using _clock = std::chrono::high_resolution_clock;
using _duration = std::chrono::duration<uint64_t, std::nano>;

class Chronometer {
public:
    Chronometer();
    ~Chronometer() = default;

    uint64_t tick();
private:
    std::chrono::time_point<std::chrono::system_clock> start;
};
