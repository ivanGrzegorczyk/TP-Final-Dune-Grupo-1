#include <cstdint>
#include <stack>
#include <netinet/in.h>
#include <iostream>

#include "../headers/ServerProtocol.h"

ServerProtocol::ServerProtocol(const std::string& host) : socket(host.c_str()), socket_closed(false) {}

ServerProtocol::ServerProtocol(Socket &&peer) : socket(std::move(peer)), socket_closed(false) {}

Socket ServerProtocol::accept() {
    return socket.accept();
}

void ServerProtocol::shutdown(int how) {
    socket.shutdown(how);
    socket.close();
    socket_closed = true;
}

int ServerProtocol::commandReceive() {
    uint16_t command;
    socket.recvall(&command, 1);
    return command;
}

void ServerProtocol::getRelocationData
    (uint16_t &id, coordenada_t &goal) {
    uint16_t unitId;
    uint16_t goal_x;
    uint16_t goal_y;

    socket.recvall(&unitId, sizeof(unitId));
    socket.recvall(&goal_x, sizeof(goal_x));
    socket.recvall(&goal_y, sizeof(goal_y));

    id = ntohs(unitId);
    goal.first = ntohs(goal_x);
    goal.second = ntohs(goal_y);
}

void ServerProtocol::getUnitData(uint8_t &unity, coordenada_t &position) {
    socket.recvall(&unity, sizeof(unity));
    uint16_t aux;
    socket.recvall(&aux, sizeof(aux));
    position.first = ntohs(aux);
    socket.recvall(&aux, sizeof(aux));
    position.second = ntohs(aux);
}

void ServerProtocol::assignPlayerId(int id) {
    uint16_t playerId = id;
    playerId = htons(playerId);

    socket.sendall(&playerId, sizeof(playerId));
}

void ServerProtocol::sendSnapshot(const std::vector<uint16_t> &snapshot) {
    for (auto msg : snapshot) {
        uint16_t aux = htons(msg);
        socket.sendall(&aux, sizeof(aux));
    }
}
