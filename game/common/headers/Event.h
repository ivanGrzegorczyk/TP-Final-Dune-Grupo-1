#ifndef EVENT_H_
#define EVENT_H_

#include <string>

class Event {
private:
    std::string event;

public:
    Event() = default;

    Event(Event&&) noexcept;
    Event& operator=(Event&&) noexcept;

    Event(const Event&) = delete;
    Event& operator=(const Event&) = delete;
};

#endif  // EVENT_H_
