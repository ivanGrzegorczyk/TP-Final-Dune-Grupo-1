#ifndef BLOCKINGQUEUE_H_
#define BLOCKINGQUEUE_H_

#include <mutex>
#include <queue>
#include <condition_variable>
#include <atomic>

template<class T>
class BlockingQueue {
private:
    std::queue<T> data;
    std::mutex mutex;
    std::condition_variable conditionVariable;
    std::atomic<bool> closed;

    void stop();

public:
    BlockingQueue();

    void push(T t);
    T pop();

    BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue& operator=(const BlockingQueue&) = delete;
};

#endif  // BLOCKINGQUEUE_H_
