#include "../headers/Celda.h"

CeldaAStar::CeldaAStar(int fila, int columna) {
    id.first = fila;
    id.second = columna;
    id_anterior = {-1, -1};
}
CeldaAStar::CeldaAStar() {
    id = {-1, -1};
    id_anterior = {-1, -1};
}
CeldaAStar::CeldaAStar(coordenada_t coordenada) {
    id = coordenada;
    id_anterior = {-1, -1};
}

bool CeldaAStar::operator==(const CeldaAStar &other) const {
    return (this->id == other.id);
}

bool CeldaAStar::operator<(const CeldaAStar &other) {
    return this->f_value < other.f_value;
}

bool CeldaAStar::operator>(const CeldaAStar &other) {
    return this->f_value > other.f_value;
}

//Celda::Celda(Celda&& other)  noexcept {
//    this->id = other.id;
//    this->id_anterior = other.id_anterior;
//    this->f_value = other.f_value;
//    this->g_value = other.g_value;
//    this->h_value = other.h_value;
//
//    other.id = {0, 0};
//    other.id_anterior = {0, 0};
//    other.f_value = 0;
//    other.g_value = 0;
//    other.h_value = 0;
//}
//
//Celda& Celda::operator=(Celda&& other)  noexcept {
//    if (this == &other)
//        return *this;
//
//    this->id = other.id;
//    this->id_anterior = other.id_anterior;
//    this->f_value = other.f_value;
//    this->g_value = other.g_value;
//    this->h_value = other.h_value;
//
//    other.id = {0, 0};
//    other.id_anterior = {0, 0};
//    other.f_value = 0;
//    other.g_value = 0;
//    other.h_value = 0;
//
//    return *this;
//}
