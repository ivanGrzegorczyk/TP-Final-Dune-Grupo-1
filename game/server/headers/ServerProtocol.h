#ifndef SERVERPROTOCOL_H_
#define SERVERPROTOCOL_H_

#include <utility>
#include <string>
#include <vector>

#include "../../common/headers/Socket.h"
#include "../../common/headers/Entity.h"

#define REPOSITION_EVENT 1

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
};

#endif  // SERVERPROTOCOL_H_