#ifndef NAVEGADOR_H_
#define NAVEGADOR_H_

#include <vector>
#include "Mapa.h"

class Navegador {
private:
    int filas;
    int columnas;
    std::vector<std::vector<Celda>> mapa;

    bool coordenadaValida(const Celda &unidad) const;
    double calcularH(coordenada_t coordenada, const Celda &destino) const;
    std::vector<Celda> armarCamino(const Celda &destino);

public:
    explicit Navegador(
            std::vector<std::vector<Celda>> &mapa, int filas, int columnas);

    std::vector<Celda> navegar(const Celda &pos_actual, const Celda &destino);
};


#endif  // NAVEGADOR_H_
