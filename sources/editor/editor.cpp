#include <iostream>
#include "../../headers/editor/mapa_editor.h"
#include <SDL.h>
#include <SDL_image.h>

#include <SDL2pp/SDL2pp.hh>
#include <string>

#include "ui_mainwindow.h"
#include "../../headers/editor/mainwindow.h"
#include <QApplication>

#include "yaml-cpp/yaml.h"
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
    YAML::Emitter out;
    out << YAML::BeginMap;
        out << YAML::Key << "name";
        out << YAML::Value << "My cool map";
    out << YAML::EndMap;
    
    std::cout << out.c_str() <<std::endl;

    MapaEditor m(std::move(setup()));
    QApplication a(argc, argv);
    MainWindow w(std::move(m));
    w.show();
    return a.exec();
}
