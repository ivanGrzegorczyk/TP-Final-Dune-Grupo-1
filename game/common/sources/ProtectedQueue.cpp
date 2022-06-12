#include "../headers/ProtectedQueue.h"

template<class T>
void ProtectedQueue<T>::push(T t) {
    std::lock_guard<std::mutex> lock(mutex);
    data.push(t);
}

template<class T>
T ProtectedQueue<T>::pop() {
    std::lock_guard<std::mutex> lock(mutex);

    if (data.empty())
        return nullptr;

    T t = data.front();
    data.pop();
    return t;
}
