#include "../headers/CeldaServidor.h"

Celda::Celda(coordenada_t id) : id(id) {}
Celda::Celda() : id({-1,-1}) {}


Celda::Celda(Celda&& other)  noexcept {
   this->id = other.id;
   other.id = {0, 0}; //is this coordinate invalid? i dont think so
}

Celda& Celda::operator=(Celda&& other)  noexcept {
   if (this == &other)
       return *this;
   this->id = other.id;
   other.id = {0, 0};
   return *this;
}
