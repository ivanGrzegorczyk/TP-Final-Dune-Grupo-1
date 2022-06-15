#include "../headers/Game.h"
#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"

using namespace SDL2pp;

int main(int argc, char* argv[]) { //run()
    //thread1(&Client::sendToClient, this);
    //thread2(&Client::receiveOfClient, this);
    SDL sdl(SDL_INIT_VIDEO);
    Window window("Client", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,640, 480, SDL_WINDOW_RESIZABLE);
    Renderer render(window, -1, SDL_RENDERER_ACCELERATED);
    Game game(render, argv[1]); //port [2]

    while(game.running()) {
        game.processInput();
        game.update();
        game.renderer();
        usleep(10000000.0f/25.0f);
    }
    return 0;
}


void Client::receiveOfClient() {

}

void Client::sendToClient() {
}

Client::Client() {

}
