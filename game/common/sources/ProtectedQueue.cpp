#include "../headers/ProtectedQueue.h"

void ProtectedQueue::push(Event &&event) {
    std::lock_guard<std::mutex> lock(mutex);
    events.push(std::move(event));
}

Event ProtectedQueue::pop() {
    std::lock_guard<std::mutex> lock(mutex);

    if (events.empty())  // TODO Cuando sea polimorfico devuelvo nullptr
        return {};

    Event event = std::move(events.front());
    events.pop();
    return std::move(event);
}
