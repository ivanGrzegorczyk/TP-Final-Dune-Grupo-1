#include <iostream>
#include "../../headers/editor/mapa_editor.h"
int main() {
    MapaEditor m(5,5);
    m.imprimir();
    coordenada_t construccion = {1,3};
    m.colocar_centro_construccion(construccion);
    std::cout << m.centro_construccion();

    coordenada_t construccion2 = {4,1};
    m.colocar_centro_construccion(construccion2);
    std::cout << m.centro_construccion() << std::endl;
    std::vector<coordenada_t> celdas_montania;
    celdas_montania.push_back({3,3});
    celdas_montania.push_back({3,4});
    m.poner_terreno(celdas_montania, "montania");
    m.imprimir();
}
