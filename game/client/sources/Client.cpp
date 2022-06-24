#include <thread>
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include "../headers/CreateLightInfantry.h"
#include "client/headers/ReceiveThread.h"
#include "client/headers/SendThread.h"

using namespace SDL2pp;

Client::Client(const std::string& hostname, const std::string&  servicename, Renderer &rnd) :
    protocol(hostname, servicename), mapUi(rnd),clientId(), running(true) {
}

void Client::run() {
    this->clientId = protocol.receiveId();
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


    auto t1 = std::chrono::system_clock::now();
    while(running) {
        ProcessInput();
        update();
        renderer();
        auto t2 = std::chrono::system_clock::now();
        auto delta = simDeltaTime(t1, t2);
        sleep(t1, t2, delta);
    }
    protocol.shutdown();
    receiveThread.close();
    sendThread.close();
    receiveThread.join();
    sendThread.join();
   /* threadReceive.join();
    threadSend.join();*/
}

void Client::ProcessInput() {
    Request *event = createEvent();
    if(event != nullptr) {
        std::cout << "pusheo" << std::endl;

        sendQueue.push(event);
    }
}

Request* Client::createEvent() {
    SDL_Event event;
    Request* req = nullptr;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_a:
                    int x = -1 ,y = -1;
                    SDL_GetMouseState(&x, &y);
                    Request *unit = new CreateLightInfantry(x / 16, y / 16);
                    req = unit;
                    break;
            }
        case SDL_MOUSEBUTTONUP:
            if(event.button.button ==  SDL_BUTTON_RIGHT) {
                Request* request;
                int x, y;
                x = event.button.x;
                y = event.button.y;
                request = mapUi.moveCharacter(x / 16, y / 16, clientId);
                req = request;
                break;
            }
            else if(event.button.button == SDL_BUTTON_LEFT) {
                Request* r;
                int x, y;
                x = event.button.x;
                y = event.button.y;
                r =  mapUi.mouseEvent(x, y, clientId);
                req = r;
                break;
            }
        default:
            break;
    }

    return req;
}

void Client::update() {
    Response* response = this->recvQueue.pop();
    if (response != nullptr) {
        this->mapUi.update(response);
    }
}

/*void Client::sendToServer() {
    while(running) {
        std::vector<uint16_t> data;
        Request *event = this->sendQueue.pop();
        std::cout << "entroooo a pop" << std::endl;

        if (event != nullptr) {
            std::cout << "data" << std::endl;
            data = event->getData();
            protocol.send(event->getCommand(), data);
        }
        std::cout << "nulo" << std::endl;

    }
}*/

/*void Client::receiveOfServer() {
    while(running) {
        Response* response =  protocol.recvResponse();
        this->recvQueue.push(response);
    }
}*/

void Client::renderer() {
    mapUi.render();
}