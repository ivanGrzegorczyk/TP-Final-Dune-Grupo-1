#include <iostream>
#include <algorithm>
#include <complex>
#include <stack>
#include <array>
#include <stdexcept>
#include "../headers/Navegador.h"

Navegador::Navegador(const size_t filas, const size_t columnas) :
        filas(filas), columnas(columnas), mapa(filas, std::vector<CeldaAStar>(columnas)) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            mapa[i][j].f_value = INFINITY;
            mapa[i][j].g_value = INFINITY;
            mapa[i][j].h_value = INFINITY;
            mapa[i][j].id_anterior = {-1, -1};
            mapa[i][j].id = {i, j};
        }
    }
}

bool Navegador::coordenadaValida(
        const CeldaAStar &CeldaAStar) const {
    return !(CeldaAStar.id.first >= columnas 
        || CeldaAStar.id.second >= filas
        || CeldaAStar.id.first < 0 
        || CeldaAStar.id.second < 0);
}

double Navegador::calcularH(coordenada_t coordenada, const CeldaAStar &destino) const {
    return std::sqrt(std::pow(destino.id.first - coordenada.first, 2)
                     + std::pow(destino.id.second - coordenada.second, 2) * 1.0);
}

std::vector<CeldaAStar> Navegador::armarCamino(const CeldaAStar &destino) {
    std::cout << "Found a camino" << std::endl;
    int x = destino.id.first;
    int y = destino.id.second;
    std::stack<CeldaAStar> camino;
    std::vector<CeldaAStar> usablePath;

    while (!(mapa[x][y].id_anterior.first == x
             && mapa[x][y].id_anterior.second == y)
           && mapa[x][y].id.first != -1 && mapa[x][y].id.second != -1)
    {
        camino.push(mapa[x][y]);
        int tempX = mapa[x][y].id_anterior.first;
        int tempY = mapa[x][y].id_anterior.second;
        x = tempX;
        y = tempY;

    }
    camino.push(mapa[x][y]);

    while (!camino.empty()) {
        CeldaAStar top = camino.top();
        camino.pop();
        usablePath.emplace_back(top);
    }
    return usablePath;
}
std::vector<CeldaAStar> Navegador::navegar(const coordenada_t& _pos_actual, const coordenada_t& _destino) {
    CeldaAStar pos_actual(_pos_actual);
    CeldaAStar destino(_destino);
    // Vector con las CeldaAStars que fueron evaluadas
    std::vector<std::vector<bool>>  cerrado(filas, std::vector<bool>(columnas));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cerrado[i][j] = false;
        }
    }
    if (!coordenadaValida(pos_actual) ||
        !coordenadaValida(destino) || pos_actual == destino) {
        throw std::invalid_argument("Invalid coordinate!");
    }

    int x = pos_actual.id.first, y = pos_actual.id.second;
    mapa[x][y].f_value = 0;
    mapa[x][y].g_value = 0;
    mapa[x][y].h_value = 0;
    mapa[x][y].id_anterior.first = x;
    mapa[x][y].id_anterior.second = y;
    std::vector<CeldaAStar> abierto;
    abierto.emplace_back(mapa[x][y]);

    while (!abierto.empty() && (int)abierto.size() < filas * columnas) {
        CeldaAStar c;
        do {
            float temp = INFINITY;
            std::vector<CeldaAStar>::iterator itCeldaAStar;
            for (auto it = abierto.begin();
                 it != abierto.end(); it = next(it)) {
                CeldaAStar n = *it;
                if (n.f_value < temp) {
                    temp = n.f_value;
                    itCeldaAStar = it;
                }
            }
            c = *itCeldaAStar;
            abierto.erase(itCeldaAStar);
        } while (!coordenadaValida(c));

        x = c.id.first;
        y = c.id.second;
        cerrado[x][y] = true;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                double g_aux, h_aux, f_aux;
                CeldaAStar c(x + i, y + j);
                if (!coordenadaValida(c))  break;
                if (destino == c) {
                    //Destination found - make path
                    mapa[x + i][y + j].id_anterior.first = x;
                    mapa[x + i][y + j].id_anterior.second = y;
                    return armarCamino(destino);
                } else if (!cerrado[x + i][y + j]) {
                    g_aux = c.g_value + 1.0;
                    coordenada_t coord{x + i, y + j};
                    h_aux = calcularH(coord, destino);
                    f_aux = g_aux + h_aux;
                    // Check if this path is better than the one already present
                    if (mapa[x + i][y + j].f_value > f_aux) {
                        // Update the details of this neighbour node
                        mapa[x + i][y + j].f_value = f_aux;
                        mapa[x + i][y + j].g_value = g_aux;
                        mapa[x + i][y + j].h_value = h_aux;
                        mapa[x + i][y + j].id_anterior.first = x;
                        mapa[x + i][y + j].id_anterior.second = y;
                        abierto.emplace_back(mapa[x + i][y + j]);
                    }
                }
            }
        }
    }
    throw std::invalid_argument("No valid path found");
}
