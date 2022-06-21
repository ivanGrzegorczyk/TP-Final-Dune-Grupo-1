#include "client/headers/UpdateUnit.h"

void UpdateUnit::modify(MapUi &mapUi) {
    //llama a un metodo de mapUi para modificar el vector de unidades de este

}

UpdateUnit::UpdateUnit(int player, int type, int characterId, coordenada_t coord): player(player),
                                        type(type), characterId(characterId), coord(coord){
}
