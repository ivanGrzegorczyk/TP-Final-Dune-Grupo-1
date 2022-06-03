#ifndef SERVERMAP_H_
#define SERVERMAP_H_

#include "ServerCell.h"
#include "Navigator.h"

class ServerMap {
private:
    int filas, columnas;
    std::vector<Building> buildings;  // TODO: Quizas lo podemos poner en un diccionario con clave el id (consultar)

    void mostrar();
    void mostrar(std::stack<coordenada_t> path);

public:
    ServerMap(int filas, int columnas);

    std::vector<std::vector<ServerCell>> map;

    void A_star(coordenada_t start, coordenada_t end);
};

#endif  // SERVERMAP_H_