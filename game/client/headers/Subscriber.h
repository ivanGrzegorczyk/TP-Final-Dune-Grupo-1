#ifndef TP_FINAL_DUNE_GRUPO_1_Subscriber_H
#define TP_FINAL_DUNE_GRUPO_1_Subscriber_H
#include "SDL2pp/SDL2pp.hh"

class Subscriber {
public:
    virtual void notify(SDL_Event event) = 0;
};

#endif //TP_FINAL_DUNE_GRUPO_1_Subscriber_H
