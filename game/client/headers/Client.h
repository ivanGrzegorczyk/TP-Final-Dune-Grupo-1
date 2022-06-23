#ifndef TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#define TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#include <unistd.h>
#include "../../common/headers/BlockingQueue.h"
#include "../../common/headers/ProtectedQueue.h"
#include "Response.h"
#include "MapUi.h"
#include "Protocol.h"

class Client {
private:
    Protocol protocol;
    int clientId;
    MapUi mapUi;
    std::atomic<bool> running;
    BlockingQueue<Request *> sendQueue;
    ProtectedQueue<Response *> recvQueue;


public:
    Client(const std::string& hostname, const std::string& servicename, Renderer &rnd);
    void run();

    void sendToServer();

    void receiveOfServer();

    void ProcessInput();

    void update();

    void renderer();
};


#endif //TP_FINAL_DUNE_GRUPO_1_CLIENT_H
