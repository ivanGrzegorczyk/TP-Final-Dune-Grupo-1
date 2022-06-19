/********************************************************************************
** Form generated from reading UI file 'newmap.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMAP_H
#define UI_NEWMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewMap
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGraphicsView *view;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *button_container;
    QLabel *label;
    QPushButton *edit_button_1;
    QPushButton *edit_button_2;
    QPushButton *edit_button_3;
    QPushButton *building_button;
    QPushButton *save_button;
    QSpinBox *spinBox;

    void setupUi(QMainWindow *NewMap)
    {
        if (NewMap->objectName().isEmpty())
            NewMap->setObjectName(QString::fromUtf8("NewMap"));
        NewMap->resize(800, 600);
        centralwidget = new QWidget(NewMap);
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
        verticalLayoutWidget->setGeometry(QRect(250, 110, 120, 230));
        button_container = new QVBoxLayout(verticalLayoutWidget);
        button_container->setObjectName(QString::fromUtf8("button_container"));
        button_container->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        button_container->addWidget(label);

        edit_button_1 = new QPushButton(verticalLayoutWidget);
        edit_button_1->setObjectName(QString::fromUtf8("edit_button_1"));

        button_container->addWidget(edit_button_1);

        edit_button_2 = new QPushButton(verticalLayoutWidget);
        edit_button_2->setObjectName(QString::fromUtf8("edit_button_2"));

        button_container->addWidget(edit_button_2);

        edit_button_3 = new QPushButton(verticalLayoutWidget);
        edit_button_3->setObjectName(QString::fromUtf8("edit_button_3"));

        button_container->addWidget(edit_button_3);

        building_button = new QPushButton(verticalLayoutWidget);
        building_button->setObjectName(QString::fromUtf8("building_button"));

        button_container->addWidget(building_button);

        save_button = new QPushButton(verticalLayoutWidget);
        save_button->setObjectName(QString::fromUtf8("save_button"));

        button_container->addWidget(save_button);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        button_container->addWidget(spinBox);


        verticalLayout->addWidget(widget);

        NewMap->setCentralWidget(centralwidget);

        retranslateUi(NewMap);

        QMetaObject::connectSlotsByName(NewMap);
    } // setupUi

    void retranslateUi(QMainWindow *NewMap)
    {
        NewMap->setWindowTitle(QCoreApplication::translate("NewMap", "New Map", nullptr));
        label->setText(QCoreApplication::translate("NewMap", "creatng new map", nullptr));
        edit_button_1->setText(QCoreApplication::translate("NewMap", "Mountain", nullptr));
        edit_button_2->setText(QCoreApplication::translate("NewMap", "Sand", nullptr));
        edit_button_3->setText(QCoreApplication::translate("NewMap", "Rock", nullptr));
        building_button->setText(QCoreApplication::translate("NewMap", "Building", nullptr));
        save_button->setText(QCoreApplication::translate("NewMap", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewMap: public Ui_NewMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAP_H
