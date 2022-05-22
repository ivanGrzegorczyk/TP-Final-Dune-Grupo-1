#include <vector>
#include <cmath>

#include "../headers/Mapa.h"
#include "../headers/Celda.h"
#include "../headers/Navegador.h"

Mapa::Mapa(int filas, int columnas) :
        filas(filas), columnas(columnas) {
}

Mapa::Mapa(Mapa&& other)  noexcept {
    this->columnas = other.columnas;
    this->filas = other.filas;
    this->mapa = std::move(other.mapa);

    other.mapa.clear();
    other.filas = 0;
    other.columnas = 0;
}

Mapa& Mapa::operator=(Mapa&& other)  noexcept {
    if (this == &other)
        return *this;

    this->columnas = other.columnas;
    this->filas = other.filas;
    this->mapa = std::move(other.mapa);

    other.mapa.clear();
    other.filas = 0;
    other.columnas = 0;

    return *this;
}

std::vector<coordenada_t> Mapa::recorrer(const coordenada_t &inicio, const coordenada_t &objetivo) {
    Navegador navegador(filas, columnas);
    std::vector<CeldaAStar> recorrido = navegador.navegar(inicio, objetivo);
    std::vector<coordenada_t> recorrido_coord;
    for(CeldaAStar c : recorrido) {
        recorrido_coord.push_back(c.id);
    }
    return recorrido_coord;  
}
