#include <utility>
#include <iostream>

#include "../headers/ThCLient.h"

ThClient::ThClient(Socket &&peer, ProtectedQueue &protectedQueue, ServerMap &map):
        protectedQueue(protectedQueue), map(map),
        keep_talking(true), is_running(true),
        protocol(std::move(peer)) {}

void ThClient::run() {
    while (keep_talking) {
        int command = protocol.commandReceive();

        switch (command) {
            case SEARCH_PATH: {
                searchPath();  // Busco el camino y pusheo a la cola de eventos protegida
                break;
            }
            default: {
                throw std::runtime_error("Unknown command");
            }
        }
    }

    is_running = false;
}

void ThClient::sendEvent(Event &event) {
    if (event.event.at(0) == 1) {
        protocol.sendPath(event.event);
    } else {
        std::cerr << "Error en el evento" << std::endl;
    }
}

void ThClient::searchPath() {
    coordenada_t current;
    coordenada_t goal;
    protocol.requestPath(current, goal);
    std::stack<coordenada_t> path = map.A_star(current, goal);
    protectedQueue.push(std::move(Event {path}));
}

void ThClient::stop() {
    keep_talking = false;
    protocol.shutdown(SHUT_RDWR);
}

bool ThClient::isDead() {
    return !is_running;
}
