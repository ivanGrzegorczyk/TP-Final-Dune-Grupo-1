#include "../headers/BlockingQueue.h"

BlockingQueue::BlockingQueue() : closed(false) {}

void BlockingQueue::stop() {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    closed = true;
    conditionVariable.notify_all();
}

void BlockingQueue::push(Event *event) {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    events.push(event);
    conditionVariable.notify_all();
}

Event* BlockingQueue::pop() {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    while (events.empty()) {
        if (closed)
            return {};
        conditionVariable.wait(uniqueLock);
    }

    Event *event = events.front();
    events.pop();

    return event;
}
