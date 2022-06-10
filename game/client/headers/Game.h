#ifndef TP_FINAL_DUNE_GRUPO_1_GAME_H
#define TP_FINAL_DUNE_GRUPO_1_GAME_H

#include "SDL2pp/SDL2pp.hh"
#include "MapUi.h"
#include "Protocol.h"
#include "yaml-cpp/yaml.h"

using namespace SDL2pp;
class Game {
private:
    MapUi map;
    Renderer& rdr;
    Protocol protocol;
    bool isRunning;
    void sendInputToServer(int x, int y);
public:
    Game(Renderer& renderer, char* terrain);
    Renderer& getRenderer();
    bool running() const;
    void processInput();
    void update();
    void renderer();
};


#endif //TP_FINAL_DUNE_GRUPO_1_GAME_H
