#include <iostream>
#include "../../headers/editor/mapa_editor.h"
#include <SDL.h>
#include <SDL_image.h>

#include <SDL2pp/SDL2pp.hh>
#include <string>

#include "ui_mainwindow.h"
#include "editor/mainwindow.h"
#include <QApplication>
using namespace SDL2pp;

MapaEditor setup() {
    MapaEditor m(5,5);
    coordenada_t construccion = {1,3};
    m.colocar_centro_construccion(construccion);
    std::cout << m.centro_construccion();

    coordenada_t construccion2 = {4,0};
    m.colocar_centro_construccion(construccion2);
    std::cout << m.centro_construccion() << std::endl;
    std::vector<coordenada_t> celdas_montania;
    celdas_montania.push_back({3,3});
    celdas_montania.push_back({3,4});
    m.poner_terreno(celdas_montania, "montania");
    return m;
}

int main(int argc, char* argv[]) {
    MapaEditor m(std::move(setup()));
    QApplication a(argc, argv);
    MainWindow w(std::move(m));
    w.show();
    return a.exec();
}
