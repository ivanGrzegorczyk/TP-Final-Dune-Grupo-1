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
    
    Celda(const Celda&) = delete;
    Celda& operator=(const Celda&) = delete;

   // Constructor por movimiento
    Celda(Celda&&) noexcept;
    Celda& operator=(Celda&&) noexcept;
};
#endif  // CELDA_H_
