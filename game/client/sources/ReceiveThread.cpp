#include "client/headers/ReceiveThread.h"

void ReceiveThread::run() {
    while(running) {
        Response* response =  protocol->recvResponse();
        this->queue.push(response);
    }
}

void ReceiveThread::close() {
    running = false;
}

ReceiveThread::ReceiveThread(ProtectedQueue<Response *> &queue, std::shared_ptr<Protocol> protocol): queue(queue), protocol(protocol),running(true){

}
