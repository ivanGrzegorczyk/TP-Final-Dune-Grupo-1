#include "../headers/CreateBuilding.h"

std::vector<uint16_t> CreateBuilding::getData() {
    return {};
}

CreateBuilding::CreateBuilding(int idClient, int idBuilding, coordenada_t &&coord) :  idClient(idClient),
                                                                                    idBuilding(idBuilding),
                                                                                    coord(coord){

}
