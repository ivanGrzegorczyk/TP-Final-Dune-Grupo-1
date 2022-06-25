#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include <sstream>

using namespace  SDL2pp;
int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <hostname> <service>" << std::endl;
    return -1;
  }

  try{
    SDL sdl(SDL_INIT_VIDEO);
    Window window("Client", SDL_WINDOWPOS_UNDEFINED,
                  SDL_WINDOWPOS_UNDEFINED,640, 480, SDL_WINDOW_RESIZABLE);
    Renderer render(window, -1, SDL_RENDERER_ACCELERATED);
    Client client(argv[1], argv[2], render);
    client.run();
  } catch (std::exception &e) {
    std::ostringstream oss;
    oss << "[main]: " << e.what() << std::endl;
    // Para evitar RC en el flujo de error
    std::cerr << oss.str();
    return -1;
  }
  return 0;
}
