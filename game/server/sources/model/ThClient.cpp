#include <utility>
#include <iostream>

#include "server/headers/model/ThCLient.h"
#include "server/headers/events/RepositionEvent.h"
#include "server/headers/events/SpawnUnitEvent.h"
#include "server/headers/events/CreateBuildingEvent.h"
#include "server/headers/events/AttackEnemyEvent.h"
#include "server/headers/events/SpawnVehicleEvent.h"

ThClient::ThClient(Socket &&peer, ProtectedQueue<ServerEvent *> &protectedQueue, int id, int rows, int columns, std::vector<uint8_t> &terrain):
        protectedQueue(protectedQueue), keep_talking(true), is_running(true),
        protocol(std::move(peer)), playerId(id), rows(rows), columns(columns), terrain(terrain) {
    protocol.assignPlayerId(id);
    protocol.sendTerrain(columns, rows, terrain);
}

void ThClient::run() {
    try {
        while (keep_talking) {
            int command = protocol.commandReceive();
            manageCommand(command);
        }

        is_running = false;
    } catch (std::exception &e) {
        std::cerr << "[hilo thclient]: " << e.what() << std::endl;
    }
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
            break;
        }
        case CREATE_BUILDING_EVENT: {
            createBuilding();
            break;
        }
        case ATTACKING_EVENT: {
            attackEnemy();
            break;
        }
        case CREATE_VEHICLE_EVENT: {
            spawnVehicle();
            break;
        }
        default: {
            throw std::runtime_error("Unknown command: " + std::to_string(command));
        }
    }
}

void ThClient::sendSnapshot(Snapshot &snapshot) {
    protocol.sendSnapshot(snapshot);
}

void ThClient::repositionUnit() {
    uint16_t unitId;
    coordenada_t goal;
    protocol.getRelocationData(unitId, goal);
    ServerEvent *event = new RepositionEvent(playerId, unitId, goal);
    protectedQueue.push(event);
}

void ThClient::spawnVehicle() {
    uint16_t vehicle;
    coordenada_t position;
    protocol.getEntityData(vehicle, position);
    ServerEvent *event = new SpawnVehicleEvent(playerId, vehicle, position);
    protectedQueue.push(event);
}

void ThClient::spawnUnit() {
    uint16_t unit;
    uint16_t buildingId;
    protocol.getUnitData(unit, buildingId);
    ServerEvent *event = new SpawnUnitEvent(playerId, unit, buildingId);
    protectedQueue.push(event);
}

void ThClient::createBuilding() {
    uint16_t building;
    coordenada_t position;
    protocol.getEntityData(building, position);
    ServerEvent *event = new CreateBuildingEvent(playerId, building, position);
    protectedQueue.push(event);
}

void ThClient::attackEnemy() {
    int unitId, enemyId;
    protocol.getAttackingData(unitId, enemyId);
    ServerEvent *event = new AttackEnemyEvent(playerId, unitId, enemyId);
    protectedQueue.push(event);
}
