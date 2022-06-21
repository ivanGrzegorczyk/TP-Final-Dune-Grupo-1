#include <chrono>
#include <ostream>

class Chronometer {
public:
    Chronometer();
    ~Chronometer() = default;

    uint64_t now();
private:
    std::chrono::time_point<std::chrono::system_clock> start;
};
