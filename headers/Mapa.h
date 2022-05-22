#ifndef MAPA_H_
#define MAPA_H_

#include <vector>
#include "Celda.h"

class Mapa {
private:
    std::vector<std::vector<Celda>> mapa;
    int filas, columnas;

public:
    Mapa(int columnas, int filas);

    std::vector<coordenada_t> recorrer(const coordenada_t &inicio, const coordenada_t &objetivo);

    Mapa(const Mapa&) = delete;
    Mapa& operator=(const Mapa&) = delete;

    // Constructor por movimiento
    Mapa(Mapa&&) noexcept;
    Mapa& operator=(Mapa&&) noexcept;
};

#endif  // MAPA_H_
