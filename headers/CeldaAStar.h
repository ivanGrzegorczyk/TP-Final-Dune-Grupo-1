#ifndef CELDA_A_H_
#define CELDA_A_H_

#include <vector>

typedef std::pair<int, int> coordenada_t;

// TODO mover a su propio archivo
/*
Celda contiene información relevante a la lógica del juego, como el terreno.
*/

// Celda usada en el algoritmo
class CeldaAStar{
    public:
    coordenada_t id;
    coordenada_t id_anterior;

    // A* : f_value = g_value + h_value
    float f_value{}, g_value{}, h_value{};

    std::vector<CeldaAStar> vecinos;

    CeldaAStar();
    CeldaAStar(int fila, int columna);
    explicit CeldaAStar(coordenada_t coordenada);

    bool operator==(const CeldaAStar &other) const;
    bool operator<(const CeldaAStar &other);
    bool operator>(const CeldaAStar &other);
};

#endif  // CELDA_A_H_


