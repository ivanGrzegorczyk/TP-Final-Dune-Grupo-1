#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <memory>
#include "Protocol.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClientMainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::string house_chosen;
    void select_house(QPushButton *button);
    std::shared_ptr<Protocol> protocol;
    Protocol generateFromUserInput();
private:
    std::string _hostname;
    std::string _servicename;
    Ui::ClientMainWindow *ui;
};
#endif // MAINWINDOW_H
