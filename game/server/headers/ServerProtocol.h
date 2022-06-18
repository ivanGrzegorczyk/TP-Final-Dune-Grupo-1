#ifndef SERVERPROTOCOL_H_
#define SERVERPROTOCOL_H_

#include <utility>
#include <string>
#include <vector>

#include "../../common/headers/Socket.h"
#include "../../common/headers/Entity.h"
#include "../../common/headers/Constantes.h"

class ServerProtocol {
private:
    Socket socket;
    bool socket_closed;

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

    void getUnitData(uint16_t &unit, coordenada_t &position);

    void sendSnapshot(const std::vector<uint16_t> &snapshot);

    void sendTerrain();
};

#endif  // SERVERPROTOCOL_H_