#include <utility>
#include <iostream>

#include "../headers/ThCLient.h"
#include "../headers/events/RepositionEvent.h"
#include "../../common/headers/Constantes.h"
#include "../headers/events/SpawnUnitEvent.h"

ThClient::ThClient(Socket &&peer, ProtectedQueue<ServerEvent *> &protectedQueue, int id):
        protectedQueue(protectedQueue), keep_talking(true), is_running(true),
        protocol(std::move(peer)), playerId(id) {}

void ThClient::run() {
    std::cout << "Se corre el run" << std::endl;
    protocol.assignPlayerId(playerId);
    std::vector<uint16_t> broadCastInicial;
    uint16_t aux = 5;
    broadCastInicial.push_back(aux);
    broadCastInicial.push_back((uint16_t)playerId);
    aux = 10;
    broadCastInicial.push_back(aux);
    aux = 1;
    broadCastInicial.push_back(aux);
    broadCastInicial.push_back(aux);
    broadCastInicial.push_back(aux);
    protocol.sendSnapshot(broadCastInicial);

    while (keep_talking) {
        int command = protocol.commandReceive();
        std::cout << "COMANDO: " << command << std::endl;
        manageCommand(command);
    }

    is_running = false;
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
            repositionUnit();
            break;
        }
        case CREATE_UNIT_EVENT: {
            spawnUnit();
        }
        default: {
            throw std::runtime_error("Unknown command");
        }
    }
}

void ThClient::repositionUnit() {
    uint16_t unitId;
    coordenada_t goal;
    protocol.getRelocationData(unitId, goal);
    ServerEvent *event = new RepositionEvent(playerId, unitId, goal);
    protectedQueue.push(event);
}

void ThClient::spawnUnit() {
    uint8_t unit;
    protocol.getUnitData(unit);
    ServerEvent *event = new SpawnUnitEvent(playerId, unit);
    protectedQueue.push(event);
}

void ThClient::sendSnapshot(const std::vector<uint16_t> &snapshot) {
    std::cout << "Envia snapshot" << std::endl;
    protocol.sendSnapshot(snapshot);
}
