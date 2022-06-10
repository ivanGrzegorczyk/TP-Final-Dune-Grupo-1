#ifndef TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#define TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#include "SDL2pp/SDL2pp.hh"
#include "Protocol.h"
using namespace SDL2pp;

class Character {
private:
    SDL2pp::Texture t;
    std::vector<std::pair<int, int>> path;
    Renderer& rnd;
    Rect current;
    bool selected;
    bool isMoving;
    int pos;
    int desX;
    int desY;
    int pos_X;
    int pos_Y;
    void changeColor();
public:
    explicit Character(SDL2pp::Renderer &renderer);
    void render();
    void update();
    void move(std::vector<coordenada_t> &path);
    //void move(int x, int y);
    void mouseEvent(int x, int y);
    bool isSelected() const;
    bool reactToEvent(int x, int y, std::pair<coordenada_t, coordenada_t> &ubication);
    void searchPath(); //va a recibir las coordenadas que se clickeo
    std::pair<int, int> getCoordinates();
};


#endif //TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
