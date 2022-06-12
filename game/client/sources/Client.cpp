#include <thread>
#include "../headers/Game.h"
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include "../headers/InputEvent.h"
#include "../headers/MoveQuery.h"

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

    while(running) {
        ProcessInput();
        update();
        //renderer();
    }
    threadReceive.join();
    threadSend.join();
}

void Client::ProcessInput() {
    Event *event = createEvent();
    if(event != nullptr) {
        sendQueue.push(event);
    }
    //sendQueue.push(event);
}

Event Client::createEvent() {
    //std::stack<coordenada_t> ubication;
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
                map.mouseEvent(x, y);
                if(map.hasAPin()) {

                    //return MoveQuery();
                    //mando coordenadas al server
                } else {
                    //evento dummy
                }
                break;
            default:
                break;
        }
    }
}

void Client::update() {
    Event event = this->recvQueue.pop(); //puntero
    ///if(event) {
       // event.ejecutar(map);
    //}
}

Event Client::GetEventByid(int id) {
    switch (id) {
        case SEARCH_PATH: {
            Event event;
            std::stack<coordenada_t> path = protocol.receivePath();

            break;
        }
        default: {
            throw std::runtime_error("Unknown command");
        }
    }
}


//hilos
void Client::sendToServer() {
    while(running) {
        Event *event = this->sendQueue.pop();
        //if(event)
            protocol.enviar(event.event);
    }
}

void Client::receiveOfServer() {
    while(running) {
        Event *event;
        int id = protocol.commandReceive();
        event = GetEventByid(id);
       // this->recvQueue.push(event);
    }
}
