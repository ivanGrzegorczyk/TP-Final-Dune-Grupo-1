#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gamescene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GameScene scene;
    void toggle_button();
};
#endif // MAINWINDOW_H
