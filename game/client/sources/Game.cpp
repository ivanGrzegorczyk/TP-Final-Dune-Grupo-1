#include "../headers/Game.h"

void Game::sendInputToServer(int x, int y) {
    std::pair<coordenada_t, coordenada_t> ubication;
    bool walk = map.mouseEvent(x, y, ubication);
    if(walk) {
        std::cout << "ready to walk" << std::endl;
        this->protocol.sendUbication(ubication);
        std::vector<coordenada_t> path = this->protocol.receivePath();
        map.moveCharacter(path);
    }

    //vector<coordenada_t> = protocol->receivePath();
    //map.receivePath(vector);
}

void Game::processInput() {
    SDL_Event event;
    std::vector<coordenada_t> status;
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_MOUSEBUTTONUP:
                int x, y;
                x = event.button.x;
                y = event.button.y;
                sendInputToServer(x, y);
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    map.update();
}

void Game::renderer() {
    rdr.Clear();
    map.render();
    rdr.Present();
}

Game::Game(Renderer& renderer, char* terrain): map(renderer ,terrain), rdr(renderer), isRunning(true) {

}

bool Game::running() const {
     return isRunning;
}

Renderer& Game::getRenderer() {
    return rdr;
}
