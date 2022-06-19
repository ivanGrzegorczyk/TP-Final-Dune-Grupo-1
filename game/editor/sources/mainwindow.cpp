// Code credit FIUBA: https://github.com/Taller-de-Programacion/clases/tree/feature/bibliotecas-gui/bibliotecas-gui/qt5

#include "../../game/editor/headers/mainwindow.h"
#include <QString>
#include "../../game/editor/headers/editorwindow.h"
#include "ui_mainwindow.h"
#include "ui_newmap.h"

MainWindow::MainWindow(std::shared_ptr<MapaEditor> map, QWidget *parent)
    : QMainWindow(parent), 
    ui(new Ui::MainWindow),
    map(map),
    scene(map) //Todo dont create shared pointer
{}

void MainWindow::toggle_button(QPushButton *button) {
    std::string std(button->text().toStdString());
    scene.set_active_texture(std);
}

void MainWindow::place_building() {
    std::string std("building");
    scene.set_active_texture(std);
}

void MainWindow::open_map(QMainWindow *parent) {
    ui->setupUi(parent);
    ui->view->setScene(&this->scene);

    std::vector<QString> textures;
    textures.push_back(QString::fromStdString("mountain"));
    textures.push_back(QString::fromStdString("sand"));
    textures.push_back(QString::fromStdString("rock"));


    std::vector<QPushButton *> buttons;
    buttons.push_back(ui->edit_button_1);
    buttons.push_back(ui->edit_button_2);
    buttons.push_back(ui->edit_button_3);

    for (int i = 0; i < 3; i++) {
        QString texture = textures[i];
        QPushButton *button = buttons[i];
        button->setCheckable(true);
        buttons[i]->setText(texture);
        auto lambda =  [button, this]() { this->toggle_button(button); };
        connect(buttons[i], &QPushButton::clicked, this, lambda);
    }
    auto lambda_save =  [this]() { this->scene.save(); };
    auto lambda_build =  [this]() { this->place_building(); };
    connect(ui->save_button, &QPushButton::clicked, this, lambda_save);
    connect(ui->building_button, &QPushButton::clicked, this, lambda_build);
}


MainWindow::~MainWindow()
{
    delete ui;
}
