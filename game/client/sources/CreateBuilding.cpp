#include "../headers/CreateBuilding.h"

void CreateBuilding::send(Protocol &protocol) {
    protocol.createBuilding(this->idClient, this->idBuilding, this->coord);
}

CreateBuilding::CreateBuilding(int idClient, int idBuilding, coordenada_t &&coord) :  idClient(idClient),
                                                                                    idBuilding(idBuilding),
                                                                                    coord(coord){

}
