// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/editor/headers/editorwindow.h"
#include "../../game/editor/headers/mainwindow.h"
#include <QString>
#include "ui_mainwindow.h"
#include "ui_newmap.h"

EditorWindow::EditorWindow(QWidget *parent)
    : QMainWindow(parent), 
    ui_map(new Ui::NewMap),
    window(nullptr)
{

    //setup
    ui_map->setupUi(this);
    QPushButton *button = ui_map->open_button;
    QPushButton *button2 = ui_map->create_button;
    auto lambda =  [this]() { this->open_map(); };
    auto lambda2 =  [this]() { this->open_map(); };
    connect(button, &QPushButton::clicked, this, lambda);
    connect(button2, &QPushButton::clicked, this, lambda2);
    
}

void EditorWindow::open_map() {
    std::shared_ptr<MapaEditor> map(new MapaEditor(5,5));
    MainWindow* w = new MainWindow(map);
    w->open_map(this);
}


EditorWindow::~EditorWindow()
{
    delete ui_map;
}

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