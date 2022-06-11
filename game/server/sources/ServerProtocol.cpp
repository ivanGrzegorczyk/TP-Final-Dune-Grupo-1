#include <cstdint>
#include <stack>
#include <netinet/in.h>

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
    uint8_t command;
    socket.recvall(&command, sizeof(command));
    return command;
}

void ServerProtocol::requestPath
    (coordenada_t &current, coordenada_t &goal) {
    uint16_t current_x;
    uint16_t current_y;
    uint16_t goal_x;
    uint16_t goal_y;

    socket.recvall(&current_x, sizeof(current_x));
    socket.recvall(&current_y, sizeof(current_y));
    socket.recvall(&goal_x, sizeof(goal_x));
    socket.recvall(&goal_y, sizeof(goal_y));

    current.first = ntohs(current_x);
    current.second = ntohs(current_y);
    goal.first = ntohs(goal_x);
    goal.second = ntohs(goal_y);
}

void ServerProtocol::sendPath(const std::vector<uint16_t>& path) {
    if (path.empty()) {
        // TODO Definir caso en el que no hay camino posible
        return;
    } else {
        uint8_t command = SEARCH_PATH;
        socket.sendall(&command, sizeof(command));
    }

    uint16_t length = path.size();
    length = ntohs(length);
    socket.sendall(&length, sizeof(length));
    for (uint16_t coord : path) {
        uint16_t aux;
        aux = htons(coord);
        socket.sendall(&aux, sizeof(aux));
    }
}
