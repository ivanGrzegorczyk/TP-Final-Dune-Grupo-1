#include "client/headers/UpdateUnit.h"

#include <utility>

void UpdateUnit::modify(MapUi *mapUi) {
    mapUi->updateUnits(player, type, characterId, coord);
}

UpdateUnit::UpdateUnit(int player, int type, int characterId, coordenada_t coord): player(player),
                                        type(type), characterId(characterId), coord(std::move(coord)){
}
