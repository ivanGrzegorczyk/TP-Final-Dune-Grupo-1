#ifndef CELDA_H_
#define CELDA_H_

#include <vector>

typedef std::pair<int, int> coordenada_t;

class Celda {
public:
    coordenada_t id;
    coordenada_t id_anterior;

    // A* : f_value = g_value + h_value
    float f_value{}, g_value{}, h_value{};

    std::vector<Celda> vecinos;

    Celda();
    Celda(int fila, int columna);
    explicit Celda(coordenada_t coordenada);

    bool operator==(const Celda &other) const;
    bool operator<(const Celda &other);
    bool operator>(const Celda &other);

//    Celda(const Celda&) = delete;
//    Celda& operator=(const Celda&) = delete;
//
//    // Constructor por movimiento
//    Celda(Celda&&) noexcept;
//    Celda& operator=(Celda&&) noexcept;
};

#endif  // CELDA_H_
