#ifndef BLOCKINGQUEUE_H_
#define BLOCKINGQUEUE_H_

#include <mutex>
#include <queue>
#include <condition_variable>
#include <atomic>

#include "Event.h"

class BlockingQueue {
private:
    std::queue<Event> events;
    std::mutex mutex;
    std::condition_variable conditionVariable;

public:
    BlockingQueue() = default;

    void push(Event &&event);
    Event pop();
    bool empty();

    BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue& operator=(const BlockingQueue&) = delete;
};

#endif  // BLOCKINGQUEUE_H_
