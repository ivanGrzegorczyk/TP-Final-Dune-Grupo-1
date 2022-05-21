#ifndef NAVEGADOR_H_
#define NAVEGADOR_H_

#include <vector>
#include "Mapa.h"

class Navegador {
private:
    int filas;
    int columnas;
    Celda objetivo{};
    std::vector<std::vector<Celda>> mapa;
    // Vector con las celdas que hay que evaluar
    std::vector<Celda> abierto;
    // Vector con las celdas que fueron evaluadas
    std::vector<std::vector<bool>> cerrado;

    bool coordenadaValida(const Celda &unidad) const;
    double calcularH(coordenada_t coordenada) const;
    std::vector<Celda> armarCamino();

public:
    explicit Navegador(
        std::vector<std::vector<Celda>> &mapa, int filas, int columnas);

    std::vector<Celda> navegar(const Celda &pos_actual, const Celda &destino);
};


#endif  // NAVEGADOR_H_
