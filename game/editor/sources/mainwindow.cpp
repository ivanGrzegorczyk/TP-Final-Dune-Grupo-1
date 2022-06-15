// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/editor/headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(MapaEditor&& map, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(std::move(map))
{
    ui->setupUi(this);
    ui->view->setScene(&this->scene);
    ui->edit_button_1->setText("mountain");
    connect(ui->edit_button_1, &QPushButton::clicked, this,  [=]() { this->toggle_button(ui->edit_button_1->text()); });
}

void MainWindow::toggle_button(QString text) {
    ui->edit_button_1->setText(text);
    std::string txt = text.toStdString();
    scene.set_active_texture(txt);
}

MainWindow::~MainWindow()
{
    delete ui;
}

