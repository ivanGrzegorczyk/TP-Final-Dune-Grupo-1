#ifndef TP_FINAL_DUNE_GRUPO_1_MOVABLE_H
#define TP_FINAL_DUNE_GRUPO_1_MOVABLE_H
#include "SDL2pp/SDL2pp.hh"

using namespace SDL2pp;
class movable {
private:
    bool &selected;
    Rect &current;
public:

    explicit movable(Rect &current, bool &selected);

    void setSelected(bool selected);

    bool containsCoordinates(int x, int y) const;

    void normalColor(Texture &texture);

    void highlight(Texture &texture);

    bool walkEvent(int x, int y);
};


#endif //TP_FINAL_DUNE_GRUPO_1_MOVABLE_H
