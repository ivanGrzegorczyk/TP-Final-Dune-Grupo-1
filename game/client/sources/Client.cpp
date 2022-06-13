#include <thread>
#include "../headers/Game.h"
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include "../headers/Request.h"
#include "../headers/MoveQuery.h"

using namespace SDL2pp;

Client::Client(const char* hostname, const char* servicename) : clientId(-1) ,protocol(hostname, servicename) {
    this->clientId = protocol.getId();
}

void Client::run(char *file) {
    std::thread threadReceive(&Client::receiveOfServer, this);
    std::thread threadSend(&Client::sendToServer, this);

    SDL sdl(SDL_INIT_VIDEO);
    Window window("Client", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,640, 480, SDL_WINDOW_RESIZABLE);
    Renderer render(window, -1, SDL_RENDERER_ACCELERATED);

    while(running) {
        ProcessInput(); //pop y mandarlo al mapa
        update();
        renderer();
    }
    threadReceive.join();
    threadSend.join();
}

void Client::ProcessInput() {
    Request *event = createEvent();
    if(event) {
        sendQueue.push(event);
    }
    //sendQueue.push(event);
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
                xmouse = event.button.x;
                ymouse = event.button.y;
                Request *query =  mapUi.mouseEvent(xmouse, ymouse);
                return query;
            default:
                break;
        }
    }
}

void Client::update() {
    //Request* event = this->recvQueue.pop(); //puntero
    ///if(event) {
       // event.ejecutar(map);
    //}
}



void Client::sendToServer() {
    while(running) {
        Request *event = this->sendQueue.pop();
        event->send(this->protocol);
    }
}

void Client::receiveOfServer() {
    while(running) {
        Request *event;
        int id = protocol.commandReceive();
       // event = GetEventByid(id);
       // this->recvQueue.push(event);
    }
}

void Client::renderer() {
    mapUi.render();
}