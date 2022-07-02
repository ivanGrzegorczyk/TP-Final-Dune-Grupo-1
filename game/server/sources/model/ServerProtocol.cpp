#include <cstdint>
#include <stack>
#include <netinet/in.h>
#include <iostream>
#include <cstring>

#include "server/headers/model/ServerProtocol.h"
#include "server/headers/model/Room.h"

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
    goal.first = ntohs(goal_y);
    goal.second = ntohs(goal_x);
}

void ServerProtocol::getEnityData(uint16_t &type, coordenada_t &position) {
    uint16_t aux;
    socket.recvall(&aux, sizeof(aux));
    type = ntohs(aux);
    socket.recvall(&aux, sizeof(aux));
    position.second = ntohs(aux);
    socket.recvall(&aux, sizeof(aux));
    position.first = ntohs(aux);
}

void ServerProtocol::assignPlayerId(int id) {
    uint16_t playerId = id;
    playerId = htons(playerId);

    socket.sendall(&playerId, sizeof(playerId));
}

void ServerProtocol::sendSnapshot(Snapshot &snapshot) {
    std::vector<int> players = snapshot.getPlayers();
    uint16_t playerAmount = players.size();
    playerAmount = htons(playerAmount);
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
    uint16_t amount = units.size();
    amount = htons(amount);
    socket.sendall(&amount, sizeof(amount));

    for (const auto& unit : units) {
        uint8_t type = unit->getType();
        uint16_t unitId = unit->getId();
        uint16_t position_x = unit->getPosition().second;
        uint16_t position_y = unit->getPosition().first;

        unitId = htons(unitId);
        position_x = htons(position_x);
        position_y = htons(position_y);

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
        uint8_t type = building->getType();
        uint16_t buildingId = building->getId();
        uint16_t position_x = building->getPosition().second;
        uint16_t position_y = building->getPosition().first;

        buildingId = htons(buildingId);
        position_x = htons(position_x);
        position_y = htons(position_y);

        socket.sendall(&type, sizeof(type));
        socket.sendall(&buildingId, sizeof(buildingId));
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
        uint8_t type = vehicle->getType();
        uint16_t vehicleId = vehicle->getId();
        uint16_t position_x = vehicle->getPosition().second;
        uint16_t position_y = vehicle->getPosition().first;

        vehicleId = htons(vehicleId);
        position_x = htons(position_x);
        position_y = htons(position_y);

        socket.sendall(&type, sizeof(type));
        socket.sendall(&vehicleId, sizeof(vehicleId));
        socket.sendall(&position_x, sizeof(position_x));
        socket.sendall(&position_y, sizeof(position_y));
    }
}

void ServerProtocol::sendTerrain(int y_size, int x_size, std::vector<uint8_t> &terrain) {
    uint16_t _rows = y_size;
    uint16_t _columns = x_size;
    _rows = htons(_rows);
    _columns = htons(_columns);
    // Envio la cantidad de filas y columnas del mapa
    socket.sendall(&_rows, sizeof(_rows));
    socket.sendall(&_columns, sizeof(_columns));

    for (const uint8_t &ground : terrain) {
        socket.sendall(&ground, sizeof(ground));
    }
}

Room ServerProtocol::createRoom() {
    uint8_t required;
    socket.recvall(&required, sizeof(required));
    std::string name = receiveName();

    return Room {unsigned(required), name};
}

std::string ServerProtocol::receiveName() {
    uint16_t name_length;
    socket.recvall(&name_length, sizeof(name_length));
    name_length = ntohs(name_length);

    char game_name[128];
    memset(game_name, '\0', sizeof(game_name));
    socket.recvall(&game_name, name_length);

    return std::move(std::string {game_name});
}

void ServerProtocol::listRooms(std::vector<Room> &rooms) {
    uint16_t size = rooms.size();
    size = htons(size);
    socket.sendall(&size, sizeof(size));
    for (auto &room : rooms) {
        uint8_t current = room.getCurrent();
        uint8_t required = room.getRequired();
        std::string name = room.getName();
        uint16_t name_length = name.length();
        name_length = htons(name_length);
        const char *buf = name.c_str();

        socket.sendall(&current, sizeof(current));
        socket.sendall(&required, sizeof(required));
        socket.sendall(&name_length, sizeof(name_length));
        socket.sendall(buf, sizeof(buf));
    }
}
