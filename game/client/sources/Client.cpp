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
#include "client/headers/CreateBuilding.h"

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

        ProcessInput();
        update();
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
                SDL_GetMouseState(&x, &y);
                uint16_t id;
                switch (event.key.keysym.sym) {
                    case SDLK_a:
                        req = new CreateLightInfantry(x / LENGTH_TILE, y / LENGTH_TILE);
                        sendQueue.push(req);
                        break;
                    case SDLK_b:
                        id = (uint16_t)(mapUi.selectedBuilding()->code());
                        req = new CreateBuilding(x / LENGTH_TILE, y / LENGTH_TILE, id);
                        sendQueue.push(req);
                        break;
                    case SDLK_x:
                        // TODO use damage protocol
                        mapUi.damageBetween(1, 2);
                        break;
                }
            case SDL_MOUSEBUTTONUP:
                req = mapUi.handleEvent(event, clientId);
                if(req != nullptr) {
                    sendQueue.push(req);
                }
                break;
            default:
                break;
        }
    }
}

void Client::update() {
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