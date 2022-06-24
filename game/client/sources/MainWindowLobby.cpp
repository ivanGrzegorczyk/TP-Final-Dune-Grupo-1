// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/client/headers/MainWindowLobby.h"
#include <QString>
#include "ui_mainwindow.h"
#include "ui_newmap.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), 
    ui(new Ui::MainWindow) //Todo dont create shared pointer
{}

MainWindow::~MainWindow()
{
    delete ui;
}
