#ifndef TP_FINAL_DUNE_GRUPO_1_RECEIVETHREAD_H
#define TP_FINAL_DUNE_GRUPO_1_RECEIVETHREAD_H


#include <atomic>
#include "common/headers/Thread.h"
#include "Response.h"
#include "common/headers/ProtectedQueue.h"

class ReceiveThread : public Thread {
private:
    std::atomic<bool> running;
    ProtectedQueue<Response *>  &queue;
public:
    void run() override;

    void close();

    explicit ReceiveThread(ProtectedQueue<Response *> &queue);
};


#endif //TP_FINAL_DUNE_GRUPO_1_RECEIVETHREAD_H
