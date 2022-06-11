#include "../headers/BlockingQueue.h"

BlockingQueue::BlockingQueue() {}

void BlockingQueue::stop() {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    conditionVariable.notify_all();
}

void BlockingQueue::push(Event &&event) {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    events.push(std::move(event));
    conditionVariable.notify_all();
}

Event BlockingQueue::pop() {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    while (!events.empty()) {
        conditionVariable.wait(uniqueLock);
    }

    Event event = std::move(events.front());
    events.pop();

    return std::move(event);
}