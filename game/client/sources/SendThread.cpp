#include "client/headers/SendThread.h"


void SendThread::run() {
    while(running) {
        //Response *response = protocol.recvResponse();
        //this->recvQueue.push(response);
    }
}

void SendThread::close() {
    running = false;
    //shutdown
}

SendThread::SendThread(BlockingQueue<Request *> &queue): queue(queue) {

}
