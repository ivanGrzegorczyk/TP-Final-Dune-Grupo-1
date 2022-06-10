#include "../headers/Event.h"

Event::Event(Event &&other) noexcept {
    this->event = other.event;
    other.event = nullptr;
}

Event &Event::operator=(Event &&other) noexcept {
    if (this == &other)
        return *this;

    this->event = other.event;
    other.event = nullptr;

    return *this;
}
