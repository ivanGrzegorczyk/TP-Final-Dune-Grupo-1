#ifndef TP_FINAL_DUNE_GRUPO_1_RESPONSE_H
#define TP_FINAL_DUNE_GRUPO_1_RESPONSE_H
#include <cstdint>
#include <vector>
#include <map>
#include <memory>
#include "../../common/headers/Constantes.h"
#include "SDL2pp/Renderer.hh"
class MapUi;
#include "Event.h"

class Response {
protected:
    std::vector<Event*> events;

public:
    Response() = default;
    void add(Event *event);
    void update(MapUi *mapUi, SDL2pp::Renderer &renderer);
};

#endif //TP_FINAL_DUNE_GRUPO_1_RESPONSE_H

/*
response -> mapUi, event
mapui -> response, protocol, request, celda
event -> mapUi*/
