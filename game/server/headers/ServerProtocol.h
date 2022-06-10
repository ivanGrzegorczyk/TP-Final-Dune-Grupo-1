#ifndef SERVERPROTOCOL_H_
#define SERVERPROTOCOL_H_

#include <utility>
#include <string>

#include "../../common/headers/Socket.h"
#include "../../common/headers/Entity.h"

#define SEARCH_PATH 1

class ServerProtocol {
private:
    Socket socket;

public:
    ServerProtocol(std::string host);

    /**
     * @brief Receives a command from the client.
     *
     * @return command value
     */
    int commandReceive();

    /**
     * @brief Receives current position of a unit and goal position.
     * It the sets the parameters of the method values with that info.
     *
     * @param current
     * @param goal
     */
    void requestPath(coordenada_t &current, coordenada_t &goal);

    /**
     * @brief Send the shortest path a unit hasta to take in order
     * to move to nother location.
     *
     * @param path
     */
    void sendPath(std::stack<coordenada_t> path);
};

#endif  // SERVERPROTOCOL_H_