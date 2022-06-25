#include <chrono>
#include <ostream>

class Chronometer {
public:
    Chronometer();
    ~Chronometer() = default;
    void tick();
    uint64_t tack();
private:
    std::chrono::time_point<std::chrono::system_clock> start;
};
