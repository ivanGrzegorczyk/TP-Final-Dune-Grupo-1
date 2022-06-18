#include <thread>
#include <utility>
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include "../headers/CreateLightInfantry.h"

using namespace SDL2pp;

Client::Client(std::string hostname, std::string  servicename, Renderer &rnd, std::string  file) :
    protocol(std::move(hostname), std::move(servicename)), mapUi(rnd, std::move(file)),clientId(), running(true) {
}

void Client::run() {
    this->clientId = protocol.receiveId();
    this->mapUi.receiveMap(protocol);
    this->mapUi.draw();
    std::thread threadReceive(&Client::receiveOfServer, this);
    std::thread threadSend(&Client::sendToServer, this);


    auto t1 = std::chrono::system_clock::now();
    while(running) {
        ProcessInput();
        update();
        renderer();
        auto t2 = std::chrono::system_clock::now();
        auto delta = simDeltaTime(t1, t2);
        sleep(t1, t2, delta);
    }
    threadReceive.join();
    threadSend.join();
}

void Client::ProcessInput() {
    Request *event = createEvent();
    if(event != nullptr) {
        sendQueue.push(event);
    }
}

Request* Client::createEvent() {
    SDL_Event event;
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
                    return unit;
            }
        case SDL_MOUSEBUTTONUP:
            if(event.button.button ==  SDL_BUTTON_RIGHT) {
                Request* request;
                int x, y;
                x = event.button.x;
                y = event.button.y;
                request = mapUi.moveCharacter(x/16, y/16, clientId);
                return request;
            }
            if(event.button.button == SDL_BUTTON_LEFT) {
                Request* r;
                int x, y;
                x = event.button.x;
                y = event.button.y;
                r =  mapUi.mouseEvent(x, y, clientId);
                return r;
            }
        default:
            break;
    }

    return nullptr;
}

void Client::update() {
    Response* response = this->recvQueue.pop();
    if (response != nullptr) {
        this->mapUi.update(response);
    }
}

void Client::sendToServer() {
    while(running) {
        std::vector<uint16_t> data;
        Request *event = this->sendQueue.pop();
        if (event != nullptr) {
            data = event->getData();
            protocol.send(event->getCommand(), data);
        }
    }
}

void Client::receiveOfServer() {
    while(running) {
        Response *response = protocol.recvResponse();
        this->recvQueue.push(response);
    }
}

void Client::renderer() {
    mapUi.render();
}