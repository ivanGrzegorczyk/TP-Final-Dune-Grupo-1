#ifndef EVENTSQUEUE_H_
#define EVENTSQUEUE_H_

#include <queue>
#include <mutex>

#include "Event.h"

class EventsQueue {
private:
    std::queue<Event> events;
    std::mutex mutex;

public:
    EventsQueue() = default;

    void push(Event &&event);
    Event pop();
    bool empty();

    EventsQueue(const EventsQueue&) = delete;
    EventsQueue& operator=(const EventsQueue&) = delete;
};

#endif  // EVENTSQUEUE_H_