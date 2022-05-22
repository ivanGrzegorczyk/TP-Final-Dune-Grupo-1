#include <iostream>

#include "../headers/Mapa.h"

void mostrar(const std::vector<Celda>& recorrido) {
    std::cout << "RECORRIDO" << std::endl;
    for (const Celda& celda: recorrido)
        std::cout << celda.id.first << " " << celda.id.second << std::endl;
}

int main() {
    Mapa mapa(10, 10);
    Celda inicio(1, 1);
    Celda objetivo(6,6);

    std::vector<Celda> recorrido = mapa.recorrer(inicio, objetivo);

    mostrar(recorrido);

    return 0;
}
