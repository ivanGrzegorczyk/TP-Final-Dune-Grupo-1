#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"

using namespace  SDL2pp;
int main(int argc, char* argv[]) {
    SDL sdl(SDL_INIT_VIDEO);
    Window window("Client", SDL_WINDOWPOS_UNDEFINED,
                  SDL_WINDOWPOS_UNDEFINED,640, 480, SDL_WINDOW_RESIZABLE);
    Renderer render(window, -1, SDL_RENDERER_ACCELERATED);
    char * file = "terrain.txt";
    Client client(argv[1], argv[2], render, file);
    client.run();
}
