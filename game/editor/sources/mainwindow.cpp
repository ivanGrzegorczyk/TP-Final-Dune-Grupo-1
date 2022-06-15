// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/editor/headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MapaEditor&& map, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(std::move(map))
{
    ui->setupUi(this);
    ui->view->setScene(&this->scene);
    connect(ui->edit_button, &QPushButton::clicked, this, &MainWindow::toggle_button);
}

void MainWindow::toggle_button() {
    ui->edit_button->setText("Mountain");
    std::string txt("mountain");
    scene.set_active_texture(txt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

