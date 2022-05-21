#include <vector>
#include <cmath>

#include "Mapa.h"
#include "Celda.h"
#include "Navegador.h"

Mapa::Mapa(int filas, int columnas) :
    mapa(filas, std::vector<Celda>(columnas)),
    filas(filas), columnas(columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            mapa[i][j].f_value = INFINITY;
            mapa[i][j].g_value = INFINITY;
            mapa[i][j].h_value = INFINITY;
            mapa[i][j].id_anterior = {-1, -1};
            mapa[i][j].id = {i, j};
        }
    }
}

Mapa::Mapa(Mapa&& other)  noexcept {
    this->columnas = other.columnas;
    this->filas = other.filas;
    this->mapa = std::vector(other.mapa);

    other.mapa.clear();
    other.filas = 0;
    other.columnas = 0;
}

Mapa& Mapa::operator=(Mapa&& other)  noexcept {
    if (this == &other)
        return *this;

    this->columnas = other.columnas;
    this->filas = other.filas;
    this->mapa = std::vector(other.mapa);

    other.mapa.clear();
    other.filas = 0;
    other.columnas = 0;

    return *this;
}

std::vector<Celda> Mapa::recorrer(const Celda &inicio, const Celda &objetivo) {
    Navegador navegador(mapa, filas, columnas);

    return navegador.navegar(inicio, objetivo);
}
