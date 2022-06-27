#include <thread>
#include <utility>
#include <sstream>
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include "../headers/CreateLightInfantry.h"
#include "common/headers/Chronometer.h"
#include "common/headers/Constantes.h"
#include "client/headers/ReceiveThread.h"
#include "client/headers/SendThread.h"
#include "client/headers/CreateBarracks.h"

using namespace SDL2pp;

Client::Client(Protocol&& protocol, Renderer &rnd, std::string house) :
    protocol(std::move(protocol)), mapUi(rnd),clientId(), running(true) {
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

    Chronometer chronometer;
    while(running) {
        chronometer.tick();

        ProcessInput();
        update();
        renderer();
        uint64_t delta = chronometer.tack();
        if (delta < GAME_LOOP_RATE)
            usleep(GAME_LOOP_RATE - delta);
    }
    receiveThread.close();
    sendThread.close();
    receiveThread.join();
    sendThread.join();
   /* threadReceive.join();
    threadSend.join();*/
}

void Client::ProcessInput() {
    int x, y;
    SDL_Event event;
    Request* req = nullptr;
    while (running && SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                std::cout << "QUIT" << std::endl;
                running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_a:
                        SDL_GetMouseState(&x, &y);
                        req = new CreateLightInfantry(x / 16, y / 16);
                        sendQueue.push(req);
                        break;
                    case SDLK_b:
                        SDL_GetMouseState(&x, &y);
                        req = new CreateBarracks(x / 16, y / 16);
                        sendQueue.push(req);
                        break;
                }
            case SDL_MOUSEBUTTONUP:
                if(event.button.button ==  SDL_BUTTON_RIGHT) {
                    //int x, y;
                    x = event.button.x;
                    y = event.button.y;
                    req = mapUi.clickScreen(x,y,this->clientId);
                    sendQueue.push(req);
                }
                else if(event.button.button == SDL_BUTTON_LEFT) {
                    int x, y;
                    x = event.button.x;
                    y = event.button.y;
                    req =  mapUi.mouseEvent(x, y, clientId);
                    sendQueue.push(req);
                    break;
                }
            default:
                break;
        }
    }
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