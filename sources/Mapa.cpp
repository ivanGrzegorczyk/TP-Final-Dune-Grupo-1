#include <vector>
#include <cmath>

#include "../headers/Mapa.h"
#include "../headers/CeldaServidor.h"
#include "../headers/Navegador.h"

Mapa::Mapa(int filas, int columnas) :
        filas(filas), columnas(columnas) {
    for (int i = 0; i < filas; i++) {
        std::vector<Celda> fila;
        for (int j = 0; j < columnas; j++) {
            fila.push_back(Celda({i,j}));
        }
        mapa.push_back(std::move(fila));
    }
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

std::vector<Celda> Mapa::recorrer(const coordenada_t &inicio, const coordenada_t &objetivo) {
    Navegador navegador(filas, columnas);
    std::vector<CeldaAStar> recorrido_star = navegador.navegar(inicio, objetivo);
    std::vector<Celda> recorrido;
    for(CeldaAStar c : recorrido_star) {
        recorrido.push_back(std::move(mapa[c.id.second][c.id.first]));
    }
    return recorrido;  
}
