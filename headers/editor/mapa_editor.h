
#include <vector>
#include <string>
#pragma once
#include "../../headers/editor/celda_editor.h"

typedef std::vector<std::vector<CeldaEditor>> matriz_t;
typedef std::vector<CeldaEditor> fila_t;
class MapaEditor {
    matriz_t mapa;
    int filas; int columnas;
    coordenada_t ubicacion_centro_construccion = {-1,-1};
    public:
    MapaEditor(int filas, int columnas) : filas(filas), columnas(columnas) {
        for(int i = 0; i < filas; i++) {
            fila_t fila;
            for(int j = 0; j < columnas; j++) {
                CeldaEditor c({i, j});
                fila.push_back(c);
            }
            mapa.push_back(fila);
        }
    }
    const CeldaEditor& cell(coordenada_t coordinate) {
        mapa[coordinate.second][coordinate.first];
    }
    void colocar_centro_construccion(coordenada_t& coordenada) {
        // coordenada es valida
        // TODO sistema de propiedades mejor, clase mapa
        coordenada_t nula = {-1, -1};
        if(ubicacion_centro_construccion != nula) {
            mapa[ubicacion_centro_construccion.second][ubicacion_centro_construccion.first]
                .propiedades.clear();
        }
        ubicacion_centro_construccion = coordenada;
        mapa[coordenada.second][coordenada.first]
            .propiedades.emplace_back("centro_construccion");
    }
    std::string centro_construccion() {
        return mapa[ubicacion_centro_construccion.second][ubicacion_centro_construccion.first]
            .propiedades[0];
    }
    void poner_terreno(std::vector<coordenada_t> celdas, std::string terreno) {
        for(coordenada_t celda : celdas) {
            mapa[celda.second][celda.first].terreno = terreno;
        }
    }
};