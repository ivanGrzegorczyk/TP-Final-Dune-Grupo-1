/********************************************************************************
** Form generated from reading UI file 'clientmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMAINWINDOW_H
#define UI_CLIENTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGraphicsView *view;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *house_button_1;
    QPushButton *house_button_2;
    QPushButton *house_button_3;
    QPushButton *start_button;

    void setupUi(QMainWindow *ClientMainWindow)
    {
        if (ClientMainWindow->objectName().isEmpty())
            ClientMainWindow->setObjectName(QString::fromUtf8("ClientMainWindow"));
        ClientMainWindow->resize(800, 600);
        centralwidget = new QWidget(ClientMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        view = new QGraphicsView(widget);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(-10, 0, 782, 566));
        view->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 110, 342, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        house_button_1 = new QPushButton(verticalLayoutWidget);
        house_button_1->setObjectName(QString::fromUtf8("house_button_1"));

        horizontalLayout->addWidget(house_button_1);

        house_button_2 = new QPushButton(verticalLayoutWidget);
        house_button_2->setObjectName(QString::fromUtf8("house_button_2"));

        horizontalLayout->addWidget(house_button_2);

        house_button_3 = new QPushButton(verticalLayoutWidget);
        house_button_3->setObjectName(QString::fromUtf8("house_button_3"));

        horizontalLayout->addWidget(house_button_3);


        verticalLayout_2->addLayout(horizontalLayout);

        start_button = new QPushButton(verticalLayoutWidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));

        verticalLayout_2->addWidget(start_button);


        verticalLayout->addWidget(widget);

        ClientMainWindow->setCentralWidget(centralwidget);

        retranslateUi(ClientMainWindow);

        QMetaObject::connectSlotsByName(ClientMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientMainWindow)
    {
        ClientMainWindow->setWindowTitle(QCoreApplication::translate("ClientMainWindow", "New Map", nullptr));
        house_button_1->setText(QCoreApplication::translate("ClientMainWindow", "1", nullptr));
        house_button_2->setText(QCoreApplication::translate("ClientMainWindow", "2", nullptr));
        house_button_3->setText(QCoreApplication::translate("ClientMainWindow", "3", nullptr));
        start_button->setText(QCoreApplication::translate("ClientMainWindow", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientMainWindow: public Ui_ClientMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMAINWINDOW_H
