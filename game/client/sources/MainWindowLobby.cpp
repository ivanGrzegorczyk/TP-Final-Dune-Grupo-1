// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/client/headers/MainWindowLobby.h"
#include <QPushButton>
#include <QString>
#include <QApplication>
#include "ui_pickmatchwindow.h"
#include "ui_enterportwindow.h"
#include "ui_clientmainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), 
    port_ui(new Ui::EnterPortWindow),match_ui(new Ui::PickMatchWindow),ui(new Ui::ClientMainWindow), _hostname("localhost"), _servicename("8080")
{
    port_ui->setupUi(this);
    port_ui->hostname->setText(QString::fromStdString(_hostname));
    port_ui->servicename->setText(QString::fromStdString(_servicename));
    QPushButton *start_button = port_ui->start_button;
    auto pick_match =  [this]() { this->show_pick_match(); };
    std::cout << "connecting start button" << std::endl;
    connect(start_button, &QPushButton::clicked, this, pick_match);
}

void MainWindow::show_pick_match() {
    _hostname = port_ui->hostname->text().toStdString();
    _servicename = port_ui->servicename->text().toStdString();
    match_ui->setupUi(this);
    // TODO buttons come from a config file
    std::vector<std::string> matches = {"match1", "match2"};
    std::vector<QPushButton *> buttons;
    buttons.push_back(match_ui->house_button_1);
    buttons.push_back(match_ui->house_button_2);
    buttons.push_back(match_ui->house_button_3);

    for (int i = 0; i < matches.size(); i++) {
        if(i >= buttons.size()) break;
        QPushButton *button = buttons[i];
        buttons[i]->setText(QString::fromStdString(matches[i]));
        auto smatch =  [this, button]() { this->select_match(button); };
        connect(buttons[i], &QPushButton::clicked, this, smatch);
    }
    QPushButton *start_button = match_ui->start_button;
    connect(start_button, &QPushButton::clicked, this, &QMainWindow::close, Qt::QueuedConnection);
}

void MainWindow::show_pick_house() {
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

void MainWindow::select_match(QPushButton *button) {
    match_chosen = (button->text().toStdString());
}

void MainWindow::select_house(QPushButton *button) {
    house_chosen = (button->text().toStdString());
}

Protocol MainWindow::transferProtocol() {
    //TODO use seprate window to initialize protocol
    Protocol protocol(_hostname, _servicename);
    return protocol;
}

MainWindow::~MainWindow()
{
    delete ui;
}
