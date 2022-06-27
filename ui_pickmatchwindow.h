/********************************************************************************
** Form generated from reading UI file 'pickmatchwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICKMATCHWINDOW_H
#define UI_PICKMATCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PickMatchWindow
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

    void setupUi(QMainWindow *PickMatchWindow)
    {
        if (PickMatchWindow->objectName().isEmpty())
            PickMatchWindow->setObjectName(QString::fromUtf8("PickMatchWindow"));
        PickMatchWindow->resize(800, 600);
        centralwidget = new QWidget(PickMatchWindow);
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

        PickMatchWindow->setCentralWidget(centralwidget);

        retranslateUi(PickMatchWindow);

        QMetaObject::connectSlotsByName(PickMatchWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PickMatchWindow)
    {
        PickMatchWindow->setWindowTitle(QCoreApplication::translate("PickMatchWindow", "New Map", nullptr));
        house_button_1->setText(QCoreApplication::translate("PickMatchWindow", "1", nullptr));
        house_button_2->setText(QCoreApplication::translate("PickMatchWindow", "2", nullptr));
        house_button_3->setText(QCoreApplication::translate("PickMatchWindow", "3", nullptr));
        start_button->setText(QCoreApplication::translate("PickMatchWindow", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PickMatchWindow: public Ui_PickMatchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICKMATCHWINDOW_H
