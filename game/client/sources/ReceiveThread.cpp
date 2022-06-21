#include "client/headers/ReceiveThread.h"

void ReceiveThread::run() {
    while(running) {
        //Response *response = protocol.recvResponse();
        //this->recvQueue.push(response);
    }
}

void ReceiveThread::close() {
    running = false;
    //shutdown
}

ReceiveThread::ReceiveThread(ProtectedQueue<Response *> &queue): queue(queue), running(true){

}
