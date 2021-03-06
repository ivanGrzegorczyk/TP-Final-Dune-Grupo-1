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
    textures.push_back(QString::fromStdString("cliff"));
    textures.push_back(QString::fromStdString("mountain"));
    textures.push_back(QString::fromStdString("rock"));
    textures.push_back(QString::fromStdString("sand"));
    textures.push_back(QString::fromStdString("dune"));


    std::vector<QPushButton *> buttons;
    buttons.push_back(ui->terrain_cliff);
    buttons.push_back(ui->terrain_mountain);
    buttons.push_back(ui->terrain_rock);
    buttons.push_back(ui->terrain_sand);
    buttons.push_back(ui->terrain_dune);

    for (int i = 0; i < textures.size(); i++) {
        QString texture = textures[i];
        QPushButton *button = buttons[i];
        button->setCheckable(true);
        buttons[i]->setText(texture);
        auto lambda =  [button, this]() { this->toggle_button(button); };
        connect(buttons[i], &QPushButton::clicked, this, lambda);
    }
    ui->spinBox->setSingleStep(300); //TODO constant ought to be inside model
    ui->spinBox->setMaximum(900);
    auto lambda_save =  [this]() { 
        std::string filename = this->ui->filename->text().toStdString();
        this->scene.save(filename); 
    };
    auto lambda_build =  [this]() { this->place_building(); };
    auto lambda_seed =  [this](int i) { this->scene.brush->set_seed(i); };
    connect(ui->save_button, &QPushButton::clicked, this, lambda_save);
    connect(ui->building_button, &QPushButton::clicked, this, lambda_build);
    connect(ui->spinBox,QOverload<int>::of(&QSpinBox::valueChanged), this, lambda_seed);
}


MainWindow::~MainWindow()
{
    delete ui;
}
