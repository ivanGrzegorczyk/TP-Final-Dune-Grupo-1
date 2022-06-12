#include "../headers/ProtectedQueue.h"

void ProtectedQueue::push(Event *event) {
    std::lock_guard<std::mutex> lock(mutex);
    events.push(event);
}

Event* ProtectedQueue::pop() {
    std::lock_guard<std::mutex> lock(mutex);

    if (events.empty())  // TODO Cuando sea polimorfico devuelvo nullptr
        return {};

    Event *event = events.front();
    events.pop();
    return event;
}
