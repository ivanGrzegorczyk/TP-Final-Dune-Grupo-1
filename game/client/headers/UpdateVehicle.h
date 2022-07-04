#ifndef TP_FINAL_DUNE_GRUPO_1_UPDATEVEHICLE_H
#define TP_FINAL_DUNE_GRUPO_1_UPDATEVEHICLE_H


#include "Event.h"
#include "MapUi.h"
#include "common/headers/Constantes.h"

class UpdateVehicle : public Event {
private:
    int player;
    int type;
    int vehicleId;
    coordenada_t coord;
public:
    UpdateVehicle(int player, int type, int vehicleId, coordenada_t coord);
    void modify(MapUi *mapUi) override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_UPDATEVEHICLE_H
