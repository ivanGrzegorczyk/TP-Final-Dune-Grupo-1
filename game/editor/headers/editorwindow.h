#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <memory>
#include "mainwindow.h"
#include "gamescene.h"
#include "mapa_editor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class NewMap; }
QT_END_NAMESPACE

class EditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    EditorWindow(QWidget *parent = nullptr);
    ~EditorWindow();

private:
    Ui::NewMap *ui_map;
    std::shared_ptr<MainWindow> window;
    void open_new_map();
    void open_existing_map();
};
#endif // MAINWINDOW_H
