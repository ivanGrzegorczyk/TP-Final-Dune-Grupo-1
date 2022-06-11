#ifndef EVENTSQUEUE_H_
#define EVENTSQUEUE_H_

#include <queue>
#include <mutex>

#include "Event.h"

class ProtectedQueue {
private:
    std::queue<Event> events;
    std::mutex mutex;

public:
    ProtectedQueue() = default;

    void push(Event &&event);
    Event pop();

    ProtectedQueue(const ProtectedQueue&) = delete;
    ProtectedQueue& operator=(const ProtectedQueue&) = delete;
};

#endif  // EVENTSQUEUE_H_
