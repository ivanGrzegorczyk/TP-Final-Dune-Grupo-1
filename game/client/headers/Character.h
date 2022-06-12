#ifndef TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#define TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#include "SDL2pp/SDL2pp.hh"
#include "../headers/InputEvent.h"
#include "../../common/headers/Unity.h"
#include "../headers/MoveQuery.h"


using namespace SDL2pp;

class Character : public Unity {
private:
    SDL2pp::Texture t;    //std::vector<std::pair<int, int>> path;
    Renderer& rnd;
    Rect current;
    bool selected;
    bool mouseOverCharacter(int x, int y) const;
    void normalColor();
    InputEvent *walkEvent(int x, int y);
    void highlight();
    //bool isMoving;
    //int pos;
   /* int desX;
    int desY;
    int pos_X;
    int pos_Y;*/
    //void changeColor();
public:
    explicit Character(SDL2pp::Renderer &renderer);
    void render();
    void update();
    void move(std::vector<coordenada_t> &path);
    //void move(int x, int y);
    //void mouseEvent(int x, int y);
    bool isSelected() const;
    InputEvent* reactToEvent(int x, int y);
    //void searchPath(); //va a recibir las coordenadas que se clickeo
    std::pair<int, int> getCoordinates();
};


#endif //TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
