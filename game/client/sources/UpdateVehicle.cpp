#include "client/headers/UpdateVehicle.h"

#include <utility>

void UpdateVehicle::modify(MapUi *mapUi) {
    mapUi->updateVehicles(player, type, vehicleId, coord);
}

UpdateVehicle::UpdateVehicle(int player, int type, int vehicleId, coordenada_t coord): player(player),
                                                                                         type(type), vehicleId(vehicleId), coord(std::move(coord)){

}
