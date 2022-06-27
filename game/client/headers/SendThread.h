#ifndef TP_FINAL_DUNE_GRUPO_1_SENDTHREAD_H
#define TP_FINAL_DUNE_GRUPO_1_SENDTHREAD_H


#include <atomic>
#include "common/headers/Thread.h"
#include "Response.h"
#include "Request.h"
#include "Protocol.h"
#include "common/headers/BlockingQueue.h"

class SendThread : public Thread {
private:
    std::atomic<bool> running;
    BlockingQueue<Request*> &queue;
    std::shared_ptr<Protocol> protocol;
public:
    explicit SendThread(BlockingQueue<Request *> &queue, std::shared_ptr<Protocol> protocol);
    void run() override;
    void close();
};


#endif //TP_FINAL_DUNE_GRUPO_1_SENDTHREAD_H
