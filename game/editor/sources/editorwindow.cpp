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
    QPushButton *open = ui_map->open_button;
    QPushButton *create = ui_map->create_button;
    auto create_action =  [this]() { this->open_new_map(); };
    auto open_action =  [this]() { this->open_existing_map(); };
    connect(open, &QPushButton::clicked, this, open_action);
    connect(create, &QPushButton::clicked, this, create_action);
}

void EditorWindow::open_new_map() {
    int x = ui_map->x->value();
    int y = ui_map->y->value();
    int num_players = ui_map->num_players->value();
    MapaEditor* map = nullptr;
    try {
        map = new MapaEditor(x,y,num_players);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    std::shared_ptr<MapaEditor> _map(map);
    std::cout << "xy size: " << std::to_string(x) << " " << std::to_string(y) << std::endl;
    MainWindow* w = new MainWindow(_map);
    w->open_map(this);
}

void EditorWindow::open_existing_map() {
    MapaEditor* map = nullptr;
    try {
        map = MapaEditor::from_yaml("data.yaml");
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    std::shared_ptr<MapaEditor> _map(map);
    std::cout << "xy size: " << map->width() << " " << map->height() << std::endl;
    MainWindow* w = new MainWindow(_map);
    w->open_map(this);
}


EditorWindow::~EditorWindow()
{
    delete ui_map;
}