// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/client/headers/MainWindowLobby.h"
#include <QPushButton>
#include <QString>
#include <QApplication>
#include "ui_clientmainwindow.h"
// TODO get this data from common file
#define HOUSE_HARKONNEN "Harkonnen"
#define HOUSE_ORDOS "Ordos"
#define HOUSE_ATREIDES "Atreides"
#define HOUSE_NONE ""

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), 
    ui(new Ui::ClientMainWindow),
    house_chosen(HOUSE_NONE)
{
    ui->setupUi(this);

    // set up house buttons
    std::vector<std::string> housenames = {HOUSE_ATREIDES, HOUSE_HARKONNEN, HOUSE_ORDOS};
    std::vector<QPushButton *> buttons;
    buttons.push_back(ui->house_button_1);
    buttons.push_back(ui->house_button_2);
    buttons.push_back(ui->house_button_3);

    for (int i = 0; i < 3; i++) {
        QPushButton *button = buttons[i];
        buttons[i]->setText(QString::fromStdString(housenames[i]));
        auto select_house =  [this, button]() { this->select_house(button); };
        connect(buttons[i], &QPushButton::clicked, this, select_house);
    }
    QPushButton *start_button = ui->start_button;
    connect(start_button, &QPushButton::clicked, this, &QMainWindow::close, Qt::QueuedConnection);
}

void MainWindow::select_house(QPushButton *button) {
    std::string housename(button->text().toStdString());
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
