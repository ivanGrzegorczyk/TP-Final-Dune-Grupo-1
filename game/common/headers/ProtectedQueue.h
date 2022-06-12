#ifndef EVENTSQUEUE_H_
#define EVENTSQUEUE_H_

#include <queue>
#include <mutex>

template<class T>
class ProtectedQueue {
private:
    std::queue<T> data;
    std::mutex mutex;

public:
    ProtectedQueue() = default;

    void push(T t);
    T pop();

    ProtectedQueue(const ProtectedQueue&) = delete;
    ProtectedQueue& operator=(const ProtectedQueue&) = delete;
};

#endif  // EVENTSQUEUE_H_
