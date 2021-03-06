#ifndef SERVERPROTOCOL_H_
#define SERVERPROTOCOL_H_

#include <utility>
#include <string>
#include <vector>
#include <atomic>

#include "common/headers/Socket.h"
#include "ServerEntity.h"
#include "common/headers/Constantes.h"
#include "Snapshot.h"

class ServerProtocol {
private:
    Socket socket;
    std::atomic<bool> socket_closed;
    bool tiburoncin_de_la_salada;

    void sendUnitData(std::vector<std::shared_ptr<Unit>> &units);
    void sendBuildingData(std::vector<std::shared_ptr<Building>> &buildings);
    void sendVehicleData(std::vector<std::shared_ptr<Vehicle>> &vehicles);
    void sendDeadUnitsData(std::vector<std::shared_ptr<Unit>> &units);

public:
    explicit ServerProtocol(const std::string& host);

    explicit ServerProtocol(Socket &&peer);
    Socket accept();

    void shutdown(int how);

    /**
     * @brief Receives a command from the client.
     *
     * @return command value
     */
    int commandReceive();

    /**
     * @brief Receives id of a unit and goal position.
     * It then sets the parameter values with that info.
     *
     * @param goal
     */
    void getRelocationData(uint16_t &id, coordenada_t &goal);

    void assignPlayerId(int id);

    void getEntityData(uint16_t &type, coordenada_t &position);

    void sendSnapshot(Snapshot &snapshot);

    void sendTerrain(int y_size, int x_size, std::vector<uint8_t> &terrain);

    void getAttackingData(int &id, int &unitId);

    void sendTerrainData(std::map<coordenada_t, int> &terrina_data);
};

#endif  // SERVERPROTOCOL_H_