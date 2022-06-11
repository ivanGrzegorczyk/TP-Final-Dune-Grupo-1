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
    std::atomic<bool> keep_poping;

    void stop();

public:
    BlockingQueue();

    void push(Event &&event);
    void pop();

    BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue& operator=(const BlockingQueue&) = delete;
};

#endif  // BLOCKINGQUEUE_H_
