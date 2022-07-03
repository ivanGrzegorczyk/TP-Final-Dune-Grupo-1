#include <thread>
#include <utility>
#include <sstream>
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include "common/headers/Chronometer.h"
#include "common/headers/Constantes.h"
#include "client/headers/ReceiveThread.h"
#include "client/headers/SendThread.h"

using namespace SDL2pp;

Client::Client(std::shared_ptr<Protocol> protocol, Renderer &rnd, std::string house) :
    protocol(protocol), mapUi(rnd),clientId(), running(true) {
}

void Client::run() {
    this->clientId = protocol->receiveId();
    this->mapUi.receiveMap(protocol);
    this->mapUi.draw();
   /* std::thread threadReceive(&Client::receiveOfServer, this);
    std::thread threadSend(&Client::sendToServer, this);*/
    ReceiveThread receiveThread(this->recvQueue, protocol);
    SendThread sendThread(this->sendQueue, protocol);
    receiveThread.start();
    sendThread.start();

    /*std::thread threadReceive(&Client::receiveOfServer, this);
    std::thread threadSend(&Client::sendToServer, this);*/

    Chronometer chronometer;
    while(running) {
        chronometer.tick();

        ProcessInput(sendQueue);
        update(recvQueue);
        renderer();
        uint64_t delta = chronometer.tack();
        if (delta < GAME_LOOP_RATE)
            usleep(GAME_LOOP_RATE - delta);
        else {
            std::cout << "dipped under framerate" << std::endl;
        }
    }
    receiveThread.close();
    sendThread.close();
    receiveThread.join();
    sendThread.join();
   /* threadReceive.join();
    threadSend.join();*/
}

void Client::ProcessInput(BlockingQueue<Request *>& sendQueue) {
    int x, y;
    SDL_Event event;
    while (running && SDL_PollEvent(&event)) {
        Request* req = nullptr;
        if(event.type == SDL_QUIT) {
            running = false;
        } else {
            req = mapUi.handleEvent(event, clientId);
            if(req != nullptr) {
                sendQueue.push(req);
            }
        }    
    }
}

void Client::update(ProtectedQueue<Response*>& recvQueue) {
    Response* current = nullptr;
    Response* next = this->recvQueue.pop();
    while (next != nullptr) {
        current = next;
        next = this->recvQueue.pop();
    }
    if (current != nullptr) {
        this->mapUi.update(current);
        delete current;
    }
}

void Client::renderer() {
    mapUi.render();
}