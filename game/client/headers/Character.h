#ifndef TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#define TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
#include "SDL2pp/SDL2pp.hh"
#include "../../common/headers/Units.h"
#include "Request.h"


using namespace SDL2pp;

class Character : public Units {
private:
    SDL2pp::Texture t;    //std::vector<std::pair<int, int>> path;
    Renderer& rnd;
    Rect current;
    bool selected;
    bool mouseOverCharacter(int x, int y) const;
    void normalColor();
    Request *walkEvent(int x, int y);
    void highlight();
    //bool isMoving;
    //int pos;
   /* int desX;
    int desY;
    int pos_X;
    int pos_Y;*/
    //void changeColor();
public:
    Character(SDL2pp::Renderer &renderer, int id, coordenada_t coord);
    void render();
    //void move(std::vector<coordenada_t> &path);
    //void move(int x, int y);
    //void mouseEvent(int x, int y);
    bool isSelected() const;
    Request* reactToEvent(int x, int y);
    //void searchPath(); //va a recibir las coordenadas que se clickeo
    std::pair<int, int> getCoordinates();

    //void update(MapUi *map);
};


#endif //TP_FINAL_DUNE_GRUPO_1_CHARACTER_H
