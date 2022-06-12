#ifndef EVENT_H_
#define EVENT_H_

#include <string>
#include <stack>
#include <vector>

#include "Entity.h"

class Event {
protected:
public:
    Event() = default;

    explicit Event(std::stack<coordenada_t> path);

    Event(Event&&) noexcept;
    Event& operator=(Event&&) noexcept;

    Event(const Event&) = delete;
    Event& operator=(const Event&) = delete;

    virtual ~Event() = 0;
};

#endif  // EVENT_H_
