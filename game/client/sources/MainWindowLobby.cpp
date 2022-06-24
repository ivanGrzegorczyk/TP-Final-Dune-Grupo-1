// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/client/headers/MainWindowLobby.h"
#include <QString>
#include "ui_clientmainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), 
    ui(new Ui::ClientMainWindow) //Todo dont create shared pointer
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
