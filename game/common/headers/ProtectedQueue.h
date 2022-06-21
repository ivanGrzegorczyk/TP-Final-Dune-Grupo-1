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

    void push(T &t) {
        std::lock_guard<std::mutex> lock(mutex);
        data.push(std::move(t));
    }

    T pop() {
        std::lock_guard<std::mutex> lock(mutex);
        if (data.empty())
            return nullptr;

        T t = std::move(data.front());
        data.pop();
        return t;
    }

    ProtectedQueue(const ProtectedQueue&) = delete;
    ProtectedQueue& operator=(const ProtectedQueue&) = delete;
};

#endif  // EVENTSQUEUE_H_
