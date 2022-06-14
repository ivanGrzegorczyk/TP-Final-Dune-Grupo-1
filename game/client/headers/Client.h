#ifndef TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#define TP_FINAL_DUNE_GRUPO_1_CLIENT_H
#include <unistd.h>
#include "../../common/headers/BlockingQueue.h"
#include "../../common/headers/ProtectedQueue.h"

typedef std::chrono::time_point<std::chrono::system_clock> chrono;
typedef std::chrono::duration<double, std::milli> duration;

class Client {
private:
    int clientId;
    MapUi mapUi;
    std::atomic<bool> running;
    Protocol protocol;
    BlockingQueue<Request *> sendQueue;
    ProtectedQueue<Response *> recvQueue;


public:
    duration simDeltaTime(chrono &t1, chrono &t2) {
        t2= std::chrono::system_clock::now();
        auto delta= t2 - t1;
        t1 = t2;

        return delta;
    }

    void sleep(const chrono &t1, const chrono &t2, duration &delta) const {
        delta = t2 - t1;
        if (delta.count() < GAME_LOOP_RATE)
            usleep(GAME_LOOP_RATE - delta.count());
    }

    Client(const char* hostname, const char* servicename, Renderer &rnd, char * file);
    void run();
    void sendToServer();

    void receiveOfServer();

    //Event GetEventByid(int i);

    Request* createEvent();

    void ProcessInput();

    void update();

    void renderer();
};


#endif //TP_FINAL_DUNE_GRUPO_1_CLIENT_H
