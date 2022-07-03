#ifndef CHRONOMETER_H_
#define CHRONOMETER_H_

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

#endif  // CHRONOMETER_H_
