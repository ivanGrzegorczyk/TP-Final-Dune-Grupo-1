// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../headers/editor/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MapaEditor&& map, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(std::move(map))
{
    ui->setupUi(this);
    ui->view->setScene(&this->scene);
    connect(ui->edit_button, &QPushButton::clicked, this,  [=]() { this->toggle_button("mountain"); });
}

void MainWindow::toggle_button(std::string text) {
    ui->edit_button->setText(text);
    std::string txt(text);
    scene.set_active_texture(txt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

