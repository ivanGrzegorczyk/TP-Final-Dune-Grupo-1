#include "client/headers/BuildingUi.h"

void BuildingUi::render() {
    renderer.Copy(type->texture(), Rect(0, 0, 70, 70), location);
}

void BuildingUi::update() {
        //TODO
}
// TODO improve encapsulation
BuildingUi::BuildingUi(
    std::shared_ptr<BuildingType> t, 
    Renderer &renderer, 
    coordenada_t location) 
    : type(t), renderer(renderer), location(location.first, location.second, 70,70) {}


