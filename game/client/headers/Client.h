#ifndef TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#define TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#include <unistd.h>
#include "../../common/headers/BlockingQueue.h"
#include "../../common/headers/ProtectedQueue.h"
#include "Response.h"
#include "MapUi.h"
#include "Protocol.h"


typedef std::chrono::time_point<std::chrono::system_clock> chrono;
typedef std::chrono::duration<double, std::milli> duration;

class Client {
private:
    Protocol protocol;
    int clientId;
    MapUi mapUi;
    std::atomic<bool> running;
    BlockingQueue<Request *> sendQueue;
    //cambiar a std::vector<Response*>
    ProtectedQueue<Response*> recvQueue;


public:
    duration simDeltaTime(chrono &t1, chrono &t2) {
        t2= std::chrono::system_clock::now();
        auto delta= t2 - t1;
        t1 = t2;

        return delta;
    }

    void sleep(const chrono &t1, const chrono &t2, duration &delta) const {
        delta = t2 - t1;
        if (delta.count() < (1.0 / 30))
            usleep((1.0 / 30) - delta.count());
    }

    Client(const std::string& hostname, const std::string& servicename, Renderer &rnd, std::string house);
    void run();

    void sendToServer();

    void receiveOfServer();

    Request* createEvent();

    void ProcessInput();

    void update();

    void renderer();
};


#endif //TP_FINAL_DUNE_GRUPO_1_CLIENT_H
