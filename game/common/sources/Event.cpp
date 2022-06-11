#include "../headers/Event.h"

Event::Event(std::stack<coordenada_t> path) {
    event.push_back(0x01);  // TODO Esto es temporal. Hace falta refactorizar
    while (!path.empty()) {
        event.push_back(path.top().first);
        event.push_back(path.top().second);
        path.pop();
    }
}

Event::Event(Event &&other) noexcept {
    this->event = other.event;
    other.event.clear();
}

Event &Event::operator=(Event &&other) noexcept {
    if (this == &other)
        return *this;

    this->event = other.event;
    other.event.clear();

    return *this;
}
