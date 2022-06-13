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

    void stop() {
        std::unique_lock<std::mutex> uniqueLock(mutex);
        closed = true;
        conditionVariable.notify_all();
    }

public:
    BlockingQueue() : closed(false) {}

    void push(T t) {
        std::unique_lock<std::mutex> uniqueLock(mutex);
        data.push(t);
        conditionVariable.notify_all();
    }
    T pop() {
        std::unique_lock<std::mutex> uniqueLock(mutex);
        while (data.empty()) {
            if (closed)
                return {};
            conditionVariable.wait(uniqueLock);
        }

        T t = data.front();
        data.pop();

        return t;
    }

    BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue& operator=(const BlockingQueue&) = delete;
};

#endif  // BLOCKINGQUEUE_H_
