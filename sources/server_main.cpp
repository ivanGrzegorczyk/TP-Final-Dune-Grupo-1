#include <iostream>

#include "../headers/Mapa.h"

void mostrar(std::vector<Celda>& recorrido) {
    std::cout << "RECORRIDO!" << std::endl;
    for (const Celda& celda: recorrido)
        std::cout << celda.id.first << " " << celda.id.second << std::endl;
}

int main() {
    Mapa mapa(10, 10);
    coordenada_t inicio{1,1};
    coordenada_t objetivo{6,6};

    std::vector<Celda> recorrido = mapa.recorrer(inicio, objetivo);

    mostrar(recorrido);

    return 0;
}
