#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <memory>
#include "gamescene.h"
#include "mapa_editor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class NewMap; }
QT_END_NAMESPACE

MapaEditor setup();
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<MapaEditor> map, QWidget *parent = nullptr);
    ~MainWindow();
    void open_map(QMainWindow *parent);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<MapaEditor> map;
    GameScene scene;
    void toggle_button(QPushButton *text);
    void place_building();
};
#endif // MAINWINDOW_H
