#ifndef TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#define TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#include <unistd.h>
#include <thread>


class Client {
private:

public:
    Client();

    void sendToClient();

    void receiveOfClient();
};


#endif //TP_FINAL_DUNE_GRUPO_1_CLIENT_H
