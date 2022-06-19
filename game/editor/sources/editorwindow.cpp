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
    int x = ui_map->x->value();
    int y = ui_map->y->value();
    int num_players = ui_map->num_players->value();
    MapaEditor* map = nullptr;
    try {
        map = new MapaEditor(x,y,num_players);
    } catch (std::exception e) {
        return;
    }
    std::shared_ptr<MapaEditor> _map(map);
    std::cout << "xy size: " << std::to_string(x) << " " << std::to_string(y) << std::endl;
    MainWindow* w = new MainWindow(_map);
    w->open_map(this);
}


EditorWindow::~EditorWindow()
{
    delete ui_map;
}