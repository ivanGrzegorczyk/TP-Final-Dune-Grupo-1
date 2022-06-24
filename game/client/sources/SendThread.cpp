#include "client/headers/SendThread.h"


void SendThread::run() {
    while(running) {
        std::vector<uint16_t> data;
        Request *event = this->queue.pop();

        if (event != nullptr) {
            std::cout << "data" << std::endl;
            data = event->getData();
            protocol.send(event->getCommand(), data);
        }
    }
}

void SendThread::close() {
    queue.stop();
    running = false;
}

SendThread::SendThread(BlockingQueue<Request*> &queue, Protocol &protocol): running(true),queue(queue), protocol(protocol) {

}
