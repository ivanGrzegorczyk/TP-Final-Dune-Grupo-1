#include <iostream>

#include "../headers/Mapa.h"

void mostrar(std::vector<coordenada_t>& recorrido) {
    std::cout << "RECORRIDO!" << std::endl;
    for (const coordenada_t& celda: recorrido)
        std::cout << celda.first << " " << celda.second << std::endl;
}

int main() {
    Mapa mapa(10, 10);
    coordenada_t inicio{1,1};
    coordenada_t objetivo{6,6};

    std::vector<coordenada_t> recorrido = mapa.recorrer(inicio, objetivo);

    mostrar(recorrido);

    return 0;
}
