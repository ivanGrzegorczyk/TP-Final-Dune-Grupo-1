#include <thread>
#include "../headers/Game.h"
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"

using namespace SDL2pp;

Client::Client(const char* hostname, const char* servicename) : protocol(hostname, servicename){

}

void Client::run(char *file) {
    std::thread threadReceive(&Client::receiveOfServer, this);
    std::thread threadSend(&Client::sendToServer, this);

    SDL sdl(SDL_INIT_VIDEO);
    Window window("Client", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,640, 480, SDL_WINDOW_RESIZABLE);
    Renderer render(window, -1, SDL_RENDERER_ACCELERATED);

    //Game game(render, file); //arg [2]
    while(running) {
        processInput();
        //update();
        //renderer();
        usleep(10000000.0f/25.0f);
    }
    threadReceive.join();
    threadSend.join();
}


void Client::receiveOfServer() {
    int id = protocol.receiveCommandId();
    Event event = GetEventByid();
    this->recvQueue.push(event);
}

void Client::sendToServer() {
    while(running) {
        Event event = this->sendQueue.pop();
        event.sendToServer(this->protocol);
    }
}

void Client::ProcessInput() {
    Event event = createEvent();
    sendQueue.push(event);
}


void Client::cambiar() {
    Event event = this->recvQueue.pop();
    if(event) {
        event.ejecutar(map);
    }
}

Event Game::createEvent() {
    Event inputEvent;
    SDL_Event event;
    std::vector<coordenada_t> status;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONUP:
                int x, y;
                x = event.button.x;
                y = event.button.y;

                //sendInputToServer(x, y);
                break;
            default:
                break;
        }
    }
}