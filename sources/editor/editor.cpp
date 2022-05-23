#include <iostream>
#include "../../headers/editor/celda_editor.h"

typedef std::vector<std::vector<CeldaEditor>> matriz_t;
typedef std::vector<CeldaEditor> fila_t;
class MapaEditor {
    matriz_t mapa;
    //coordenada_t ubicacion_centro_construccion;
    public:
    MapaEditor(int filas, int columnas) {
        for(int i = 0; i < filas; i++) {
            fila_t fila;
            for(int j = 0; j < columnas; j++) {
                CeldaEditor c({i, j});
                fila.push_back(c);
            }
        }
    }
};
int main() {
    MapaEditor m(5,5);
}
