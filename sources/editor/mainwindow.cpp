// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "editor/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MapaEditor&& core, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(std::move(core))
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

