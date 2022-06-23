#include "../headers/Response.h"

void Response::add(Event *event) {
    this->events.push_back(event);
}

//no es necesario el render
void Response::update(MapUi *mapUi, SDL2pp::Renderer &renderer) {
   for(auto event: events) {
       event->modify(mapUi);
   }
    /*for (auto const &[player, playerData]: this->units) {
        if (unitsMap.find(player) != unitsMap.end()) {
            this->iterate(unitsMap, playerData, rdr, true, player);
        } else {
            this->iterate(unitsMap, playerData, rdr, false, player);
        }
    }*/
}