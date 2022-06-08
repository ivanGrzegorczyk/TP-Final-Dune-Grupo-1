// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->view->setScene(&this->scene);
    connect(ui->edit_button, &QPushButton::clicked, this, &MainWindow::toggle_button);
}

void MainWindow::toggle_button() {
    ui->edit_button->setText("Editing");
}

MainWindow::~MainWindow()
{
    delete ui;
}

