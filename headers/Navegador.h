#ifndef NAVEGADOR_H_
#define NAVEGADOR_H_

#include <vector>
#include "CeldaAStar.h"

class Navegador {
private:
    int filas;
    int columnas;
    std::vector<std::vector<CeldaAStar>> mapa;

    bool coordenadaValida(const CeldaAStar &unidad) const;
    double calcularH(coordenada_t coordenada, const CeldaAStar &destino) const;
    std::vector<CeldaAStar> armarCamino(const CeldaAStar &destino);

public:
    explicit Navegador(const size_t filas, const size_t columnas);

    std::vector<CeldaAStar> navegar(const coordenada_t& pos_actual, const coordenada_t& destino);
};


#endif  // NAVEGADOR_H_
