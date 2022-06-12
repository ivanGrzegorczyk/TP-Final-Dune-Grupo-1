#include "../headers/BlockingQueue.h"

template<class T>
BlockingQueue<T>::BlockingQueue() : closed(false) {}

template<class T>
void BlockingQueue<T>::stop() {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    closed = true;
    conditionVariable.notify_all();
}

template<class T>
void BlockingQueue<T>::push(T t) {
    std::unique_lock<std::mutex> uniqueLock(mutex);
    data.push(t);
    conditionVariable.notify_all();
}

template<class T>
T BlockingQueue<T>::pop() {
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
