#include "../headers/ProtectedQueue.h"

void ProtectedQueue::push(Event &&event) {
    std::lock_guard<std::mutex> lock(mutex);
    events.push(std::move(event));
}

Event ProtectedQueue::pop() {
    std::lock_guard<std::mutex> lock(mutex);

    if (events.empty())
        throw std::runtime_error("No events on queue");

    Event event = std::move(events.front());
    events.pop();
    return std::move(event);
}

bool ProtectedQueue::empty() {
    std::lock_guard<std::mutex> lock(mutex);
    return events.empty();
}
