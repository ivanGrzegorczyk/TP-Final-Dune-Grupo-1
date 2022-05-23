#include <iostream>
#include "../../headers/editor/mapa_editor.h"
int main() {
    MapaEditor m(5,5);
    m.imprimir();
    coordenada_t construccion = {1,3};
    m.colocar_centro_construccion(construccion);
    std::cout << m.centro_construccion();
}
