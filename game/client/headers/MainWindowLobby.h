#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <memory>
#include "Protocol.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EnterPortWindow; class PickMatchWindow; class ClientMainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::string house_chosen;
    std::string match_chosen;
    void show_pick_match();
    void show_pick_house();
    void select_match(QPushButton *button);
    void select_house(QPushButton *button);
    std::shared_ptr<Protocol> protocol;
private:
    std::string _hostname;
    std::string _servicename;
    Ui::EnterPortWindow *port_ui;
    Ui::PickMatchWindow *match_ui;
    Ui::ClientMainWindow *ui;
};
#endif // MAINWINDOW_H
