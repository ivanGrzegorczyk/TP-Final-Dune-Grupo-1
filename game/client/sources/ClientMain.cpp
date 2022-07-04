#include "SDL2pp/SDL2pp.hh"
#include "../headers/Client.h"
#include <sstream>
#include "client/headers/audio/audioPlayer.h"
#include "../../game/client/headers/MainWindowLobby.h"
#include <QApplication>

using namespace  SDL2pp;
int main(int argc, char* argv[]) {
  try{
    // Clase que contiene el loop principal
    QApplication app(argc, argv);
    // Instancio la ventana principal
    MainWindow ui_window;
    ui_window.show();
    /*
        * QApplication::exec inicia el event loop y se queda esperando que finalice la aplicación. Cuando el usuario
        * realice una acción que haga un exit de QT, entonces esta función retorna (con el código de error
        * si lo hubo) y entonces se podrá crear la ventana de SDL.
        */
    // exec es una función bloqueante, cuando QT finaliza su ejecución, se realiza un return con el codigo de error
    if (app.exec()) {
        throw std::runtime_error("La aplicación QT finalizó de forma incorrecta");
    }
    // get connection from the qt app
    std::shared_ptr<Protocol> protocol = ui_window.protocol;

    // launch sdl app
    SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Window window("Client", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,640, 480, SDL_WINDOW_RESIZABLE);
    Renderer render(window, -1, SDL_RENDERER_ACCELERATED);
    AudioPlayer player;
    player.play();

    // parameters obtained from lobby
    std::string house = ui_window.house_chosen;

    Client client(protocol, render, house);
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
