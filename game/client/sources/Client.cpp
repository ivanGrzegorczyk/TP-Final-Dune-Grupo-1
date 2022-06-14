#include <thread>
#include "../headers/Game.h"
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include "../headers/Request.h"
#include "../headers/MoveQuery.h"
#include "../headers/Response.h"

using namespace SDL2pp;

Client::Client(const char* hostname, const char* servicename, Renderer &rnd, char* file) : mapUi(rnd, file),
                                                                                            clientId(-1), protocol(hostname, servicename), running(true) {
    this->clientId = protocol.getId();
}

void Client::run() {
    std::thread threadReceive(&Client::receiveOfServer, this);
    std::thread threadSend(&Client::sendToServer, this);


    auto t1 = std::chrono::system_clock::now();
    while(running) {
        ProcessInput(); //pop y mandarlo al mapa
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
    if(event) {
        sendQueue.push(event);
    }
}

Request* Client::createEvent() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONUP:
                int xmouse, ymouse;
                Request* request;
                xmouse = event.button.x;
                ymouse = event.button.y;
                request =  mapUi.mouseEvent(xmouse, ymouse);
                return request;
            default:
                break;
        }
    }
}

void Client::update() {
    Response* response = this->recvQueue.pop();
    this->mapUi.update(response);
}

void Client::sendToServer() {
    while(running) {
        Request *event = this->sendQueue.pop();
        event->send(this->protocol);
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