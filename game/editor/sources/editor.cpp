#include <iostream>
#include "../../game/editor/headers/mapa_editor.h"
#include <SDL.h>
#include <SDL_image.h>

#include <SDL2pp/SDL2pp.hh>
#include "ui_mainwindow.h"
#include "ui_newmap.h"
#include "../../game/editor/headers/mainwindow.h"
#include <QApplication>

using namespace SDL2pp;

MapaEditor setup() {
    MapaEditor m(5,5);
    coordenada_t construccion = {1,3};
    m.colocar_centro_construccion(construccion);

    coordenada_t construccion2 = {4,0};
    m.colocar_centro_construccion(construccion2);
    std::vector<coordenada_t> celdas_montania;
    celdas_montania.push_back({3,3});
    celdas_montania.push_back({3,4});

    std::string name("mountain"); //TODO centralize all terrains
    std::shared_ptr<Terrain> terr(new Terrain(name));
    m.place_terrain(celdas_montania, terr);
    return m;
}

int main(int argc, char* argv[]) {

    MapaEditor* m = new MapaEditor(std::move(setup()));
    std::shared_ptr<MapaEditor> map_ptr(m);
    QApplication a(argc, argv);
    MainWindow w(map_ptr);
    w.show();
    int return_val = a.exec(); 
    return return_val;
}
