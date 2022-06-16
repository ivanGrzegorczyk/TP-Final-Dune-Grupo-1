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
    QString text1 = QString::fromStdString("mountain");
    QString text2 = QString::fromStdString("sand");
    QString text3 = QString::fromStdString("rock");
    ui->edit_button_1->setText(text1);
    ui->edit_button_2->setText(text2);
    ui->edit_button_3->setText(text3);
    auto lambda1 =  [text1, this]() { this->toggle_button(text1); };

    connect(ui->edit_button_1, &QPushButton::clicked, this, lambda1);
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

