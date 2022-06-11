#include "../headers/BlockingQueue.h"

BlockingQueue::BlockingQueue() : keep_poping(true) {}

void BlockingQueue::stop() {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    keep_poping = false;
    conditionVariable.notify_all();
}

void BlockingQueue::push(Event &&event) {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    events.push(std::move(event));
    conditionVariable.notify_all();
}

void BlockingQueue::pop() {
    while (keep_poping) {
        std::unique_lock<std::mutex> uniqueLock(mutex);
        while (!events.empty()) {
            if (!keep_poping)
                return; // TODO Esto es una salida temporal
            conditionVariable.wait(uniqueLock);
        }

        Event event = std::move(events.front());
        events.pop();
    }
}
