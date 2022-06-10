#include <cstdint>
#include <stack>
#include <netinet/in.h>

#include "../headers/ServerProtocol.h"

ServerProtocol::ServerProtocol(std::string host) : socket(host.c_str()) {}

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

void ServerProtocol::sendPath(std::stack<coordenada_t> path) {
    if (path.empty()) {
        // TODO Definir caso en el que no hay camino posible
        return;
    } else {
        uint8_t command = SEARCH_PATH;
        socket.sendall(&command, sizeof(command));
    }

    while (!path.empty()) {
        uint16_t x = path.top().first;
        x = htons(x);
        uint16_t y = path.top().second;
        y = htons(y);
        path.pop();
        socket.sendall(&x, sizeof(x));
        socket.sendall(&y, sizeof(y));
    }
}
