#include <cstdint>
#include <stack>
#include <netinet/in.h>
#include <iostream>

#include "server/headers/model/ServerProtocol.h"

ServerProtocol::ServerProtocol(const std::string& host) : socket(host.c_str()), socket_closed(false) {}

ServerProtocol::ServerProtocol(Socket &&peer) : socket(std::move(peer)), socket_closed(false) {}

Socket ServerProtocol::accept() {
    return socket.accept();
}

void ServerProtocol::shutdown(int how) {
    if (!this->socket_closed) {    
        socket.shutdown(how);
        socket.close();
        socket_closed = true;
    }
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

void ServerProtocol::getEnityData(uint16_t &type, coordenada_t &position) {
    uint16_t aux;
    socket.recvall(&aux, sizeof(aux));
    type = ntohs(aux);
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

void ServerProtocol::sendSnapshot(Snapshot &snapshot) {
    std::vector<int> players = snapshot.getPlayers();
    uint16_t playerAmount = htons(players.size());
    socket.sendall(&playerAmount, sizeof(playerAmount));

    for (auto playerId : players) {
        uint16_t id = htons(playerId);
        socket.sendall(&id, sizeof(id));
        
        std::vector<std::shared_ptr<Unit>> units = snapshot.getUnits(playerId);
        std::vector<std::shared_ptr<Building>> buildings = snapshot.getBuildings(playerId);
        std::vector<std::shared_ptr<Vehicle>> vehicles = snapshot.getVehicles(playerId);

        sendUnitData(units);
        sendBuildingData(buildings);
        sendVehicleData(vehicles);
    }
}

void ServerProtocol::sendUnitData(std::vector<std::shared_ptr<Unit>> &units) {
    uint8_t eventType = UNIT;
    socket.sendall(&eventType, sizeof(eventType));
    uint16_t amount = htons(units.size());
    socket.sendall(&amount, sizeof(amount));

    for (const auto& unit : units) {
        uint8_t type = htons((uint8_t)unit->getType());
        uint16_t unitId = htons((uint16_t)unit->getId());
        uint16_t position_x = htons((uint16_t)unit->getPosition().first);
        uint16_t position_y = htons((uint16_t)unit->getPosition().second);
        socket.sendall(&type, sizeof(type));
        socket.sendall(&unitId, sizeof(unitId));
        socket.sendall(&position_x, sizeof(position_x));
        socket.sendall(&position_y, sizeof(position_y));
    }
}

void ServerProtocol::sendBuildingData(std::vector<std::shared_ptr<Building>> &buildings) {
    uint8_t eventType = BUILDING;
    socket.sendall(&eventType, sizeof(eventType));
    uint16_t amount = htons(buildings.size());
    socket.sendall(&amount, sizeof(amount));

    for (const auto& building : buildings) {
        uint8_t type = htons((uint8_t)building->getType());
        uint16_t unitId = htons((uint16_t)building->getId());
        uint16_t position_x = htons((uint16_t)building->getPosition().first);
        uint16_t position_y = htons((uint16_t)building->getPosition().second);
        socket.sendall(&type, sizeof(type));
        socket.sendall(&unitId, sizeof(unitId));
        socket.sendall(&position_x, sizeof(position_x));
        socket.sendall(&position_y, sizeof(position_y));
    }
}

void ServerProtocol::sendVehicleData(std::vector<std::shared_ptr<Vehicle>> &vehicles) {
    uint8_t eventType = VEHICLE;
    socket.sendall(&eventType, sizeof(eventType));
    uint16_t amount = htons(vehicles.size());
    socket.sendall(&amount, sizeof(amount));

    for (const auto& vehicle : vehicles) {
        uint8_t type = htons((uint8_t)vehicle->getType());
        uint16_t unitId = htons((uint16_t)vehicle->getId());
        uint16_t position_x = htons((uint16_t)vehicle->getPosition().first);
        uint16_t position_y = htons((uint16_t)vehicle->getPosition().second);
        socket.sendall(&type, sizeof(type));
        socket.sendall(&unitId, sizeof(unitId));
        socket.sendall(&position_x, sizeof(position_x));
        socket.sendall(&position_y, sizeof(position_y));
    }
}

void ServerProtocol::sendTerrain(int rows, int columns, std::vector<uint8_t> &terrain) {
    uint16_t _rows = rows;
    uint16_t _columns = rows;
    _rows = htons(_rows);
    _columns = htons(_columns);
    // Envio la cantidad de filas y columnas del mapa
    socket.sendall(&_rows, sizeof(_rows));
    socket.sendall(&_columns, sizeof(_columns));

    for (const uint8_t &ground : terrain) {
        socket.sendall(&ground, sizeof(ground));
    }
}
