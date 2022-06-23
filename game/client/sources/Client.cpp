#include <thread>
#include <utility>
#include <sstream>
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include "../headers/CreateLightInfantry.h"
#include "common/headers/Chronometer.h"
#include "common/headers/Constantes.h"

using namespace SDL2pp;

Client::Client(const std::string& hostname, const std::string&  servicename, Renderer &rnd) :
    protocol(hostname, servicename), mapUi(rnd),clientId(), running(true) {
}

void Client::run() {
    this->clientId = protocol.receiveId();
    this->mapUi.receiveMap(protocol);
    this->mapUi.draw();
    std::thread threadReceive(&Client::receiveOfServer, this);
    std::thread threadSend(&Client::sendToServer, this);


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
    // Si algo lanza excepción antes, leakeas estos hilos. Falta RAII en estos recursos. Que sean atributos del cliente o de otro 
    // objeto RAII que los libere en su destructor
    sendQueue.stop();
    threadReceive.join();
    threadSend.join();
}

void Client::ProcessInput() {
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
                        int x = -1 ,y = -1;
                        SDL_GetMouseState(&x, &y);
                        Request *unit = new CreateLightInfantry(x / 16, y / 16);
                        sendQueue.push(unit);
                        break;
                }
            case SDL_MOUSEBUTTONUP:
                if(event.button.button ==  SDL_BUTTON_RIGHT) {
                    Request* request;
                    int x, y;
                    x = event.button.x;
                    y = event.button.y;
                    request = mapUi.moveCharacter(x / 16, y / 16, clientId);
                    sendQueue.push(request);
                }
                else if(event.button.button == SDL_BUTTON_LEFT) {
                    Request* r;
                    int x, y;
                    x = event.button.x;
                    y = event.button.y;
                    r =  mapUi.mouseEvent(x, y, clientId);
                    sendQueue.push(r);
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

void Client::sendToServer() {
    try {
         while(running) {
            std::vector<uint16_t> data;
            Request *event = this->sendQueue.pop();
            if (event != nullptr) {
                data = event->getData();
                protocol.send(event->getCommand(), data);
            }
        }
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "[sender]: " << e.what() << std::endl;
        // Para evitar RC en el flujo de error
        std::cout << oss.str();
    }
}

void Client::receiveOfServer() {
    try {
        while(running) {
            Response *response = protocol.recvResponse();
            this->recvQueue.push(response);
        }
    } catch (std::exception &e) {
        std::ostringstream oss;
        oss << "[receiver]: " << e.what() << std::endl;
        // Para evitar RC en el flujo de error
        std::cout << oss.str();
    }
}

void Client::renderer() {
    mapUi.render();
}