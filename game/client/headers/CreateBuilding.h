#ifndef TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H
#define TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H


#include "../headers/InputEvent.h"

class CreateBuilding : public InputEvent{
private:
    int idClient;
    int idBuilding;
    coordenada_t coord;
public:
    CreateBuilding(int idClient, int idBuilding, coordenada_t &&coord);
    void send(Protocol &protocol) override;
};


#endif //TP_FINAL_DUNE_GRUPO_1_CREATEBUILDING_H
