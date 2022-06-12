#include <utility>
#include <iostream>

#include "../headers/ThCLient.h"
#include "../headers/RepositionEvent.h"
#include "../../common/headers/Constantes.h"

ThClient::ThClient(Socket &&peer, ProtectedQueue<ServerEvent *> &protectedQueue):
        protectedQueue(protectedQueue), keep_talking(true), is_running(true),
        protocol(std::move(peer)) {}

void ThClient::run() {
    while (keep_talking) {
        int command = protocol.commandReceive();
        manageCommand(command);
    }

    is_running = false;
}

void ThClient::repositionUnity() {
    uint16_t id;
    coordenada_t goal;
    protocol.getRelocationData(id, goal);
    ServerEvent *event = new RepositionEvent(id, goal);
    protectedQueue.push(event);
}

void ThClient::stop() {
    keep_talking = false;
    protocol.shutdown(SHUT_RDWR);
}

bool ThClient::isDead() {
    return !is_running;
}

void ThClient::manageCommand(int command) {
    switch (command) {
        case REPOSITION_EVENT: {
            repositionUnity();
            break;
        }
        default: {
            throw std::runtime_error("Unknown command");
        }
    }
}
