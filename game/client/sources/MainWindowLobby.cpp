// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/client/headers/MainWindowLobby.h"
#include <QPushButton>
#include <QString>
#include <QApplication>
#include "ui_clientmainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), 
    ui(new Ui::ClientMainWindow), _hostname("localhost"), _servicename("8080")
{
    ui->setupUi(this);

    // TODO buttons come from a config file
    std::vector<std::string> housenames = {NAME_ATREIDES, NAME_HARKONNEN, NAME_ORDOS};
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

Protocol MainWindow::generateFromUserInput() {
    //TODO use seprate window to initialize protocol
    std::string hostname = _hostname;
    std::string servicename = _servicename;
    Protocol protocol(hostname, servicename);
    return protocol;
}

MainWindow::~MainWindow()
{
    delete ui;
}
