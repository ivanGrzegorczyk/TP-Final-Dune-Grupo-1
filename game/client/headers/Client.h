#ifndef TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#define TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#include <unistd.h>
#include "../../common/headers/BlockingQueue.h"
#include "../../common/headers/ProtectedQueue.h"


class Client {
private:
    MapUi mapUi;
    std::atomic<bool> running;
    Protocol protocol;
    BlockingQueue<InputEvent*> sendQueue;
    //ProtectedQueue<> recvQueue;


public:
    Client(const char* hostname, const char* servicename);
    void run(char *file);
    void sendToServer();

    void receiveOfServer();

    //Event GetEventByid(int i);

    InputEvent* createEvent();

    void ProcessInput();

    void update();

    void renderer();
};


#endif //TP_FINAL_DUNE_GRUPO_1_CLIENT_H
