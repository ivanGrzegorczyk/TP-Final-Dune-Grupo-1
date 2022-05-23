#ifndef CELDA_H_
#define CELDA_H_

#include <vector>

typedef std::pair<int, int> coordenada_t;

// TODO mover a su propio archivo
/*
Celda contiene información relevante a la lógica del juego, como el terreno.
*/
class Celda {
    public:
    coordenada_t id;
    Celda(coordenada_t id);
    Celda();
    
//    Celda(const Celda&) = delete;
//    Celda& operator=(const Celda&) = delete;
//
//    // Constructor por movimiento
//    Celda(Celda&&) noexcept;
//    Celda& operator=(Celda&&) noexcept;
};
// Celda usada en el algoritmo
class CeldaAStar{
    public:
    coordenada_t id;
    coordenada_t id_anterior;

    // A* : f_value = g_value + h_value
    float f_value{}, g_value{}, h_value{};

    std::vector<Celda> vecinos;

    CeldaAStar();
    CeldaAStar(int fila, int columna);
    explicit CeldaAStar(coordenada_t coordenada);

    bool operator==(const CeldaAStar &other) const;
    bool operator<(const CeldaAStar &other);
    bool operator>(const CeldaAStar &other);
};
#endif  // CELDA_H_
