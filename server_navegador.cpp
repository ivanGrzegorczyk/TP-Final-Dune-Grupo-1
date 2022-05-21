#include <iostream>
#include <algorithm>
#include <complex>
#include <stack>

#include "Navegador.h"

Navegador::Navegador(
std::vector<std::vector<Celda>> &mapa, int filas, int columnas) : 
    filas(filas), columnas(columnas), mapa(mapa),
    cerrado(filas, std::vector<bool>(columnas)) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cerrado[i][j] = false;
        }
    }
}

bool Navegador::coordenadaValida(
        const Celda &celda) const {
    if (celda.id.first >= columnas || celda.id.second >= filas
    || celda.id.first < 0 || celda.id.second < 0) {
        return false;
    } else {
        return true;
    }
}

double Navegador::calcularH(coordenada_t coordenada) const {
    return std::sqrt(std::pow(objetivo.id.first - coordenada.first, 2)
    + std::pow(objetivo.id.second - coordenada.second, 2) * 1.0);
}

std::vector<Celda> Navegador::armarCamino() {
    std::cout << "Found a camino" << std::endl;
    int x = objetivo.id.first;
    int y = objetivo.id.second;
    std::stack<Celda> camino;
    std::vector<Celda> usablePath;

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
        Celda top = camino.top();
        camino.pop();
        usablePath.emplace_back(top);
    }
    return usablePath;
}

std::vector<Celda> Navegador::navegar(const Celda& pos_actual, const Celda& destino) {
    objetivo = destino;
    if (!coordenadaValida(pos_actual) ||
        !coordenadaValida(destino) || pos_actual == destino) {
        std::cout << "Coordenada invalida" << std::endl;
        return {};
    }

    int x = pos_actual.id.first, y = pos_actual.id.second;
    mapa[x][y].f_value = 0;
    mapa[x][y].g_value = 0;
    mapa[x][y].h_value = 0;
    mapa[x][y].id_anterior.first = x;
    mapa[x][y].id_anterior.second = y;

    abierto.emplace_back(mapa[x][y]);

    while (!abierto.empty() && (int)abierto.size() < filas * columnas) {
        Celda celda;
        do {
            float temp = INFINITY;
            std::vector<Celda>::iterator itCelda;
            for (auto it = abierto.begin();
                 it != abierto.end(); it = next(it)) {
                Celda n = *it;
                if (n.f_value < temp) {
                    temp = n.f_value;
                    itCelda = it;
                }
            }
            celda = *itCelda;
            abierto.erase(itCelda);
        } while (!coordenadaValida(celda));

        x = celda.id.first;
        y = celda.id.second;
        cerrado[x][y] = true;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                double g_aux, h_aux, f_aux;
                if (coordenadaValida(Celda {x + i, y + j})) {
                    if (objetivo == Celda {x + i, y + j}) {
                        //Destination found - make path
                        mapa[x + i][y + j].id_anterior.first = x;
                        mapa[x + i][y + j].id_anterior.second = y;

                        return armarCamino();
                    } else if (!cerrado[x + i][y + j]) {
                        g_aux = celda.g_value + 1.0;
                        coordenada_t coord{x + i, y + j};
                        h_aux = calcularH(coord);
                        f_aux = g_aux + h_aux;
                        // Check if this path is better than the one already present
                        if (mapa[x + i][y + j].f_value == INFINITY ||
                            mapa[x + i][y + j].f_value > f_aux) {
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
    }

    std::cout << "No se encontro un camino valido" << std::endl;
    return {};
}
