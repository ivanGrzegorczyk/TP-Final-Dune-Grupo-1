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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_centralwidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *button_container;
    QLabel *label;
    QPushButton *edit_button_1;
    QPushButton *edit_button_2;
    QPushButton *edit_button_3;
    QPushButton *building_button;
    QPushButton *save_button;
    QSpinBox *spinBox;

    void setupUi(QWidget *centralwidget)
    {
        if (centralwidget->objectName().isEmpty())
            centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->resize(526, 400);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 511, 391));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 114, 282));
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


        retranslateUi(centralwidget);

        QMetaObject::connectSlotsByName(centralwidget);
    } // setupUi

    void retranslateUi(QWidget *centralwidget)
    {
        label->setText(QCoreApplication::translate("centralwidget", "Hi! This is a label", nullptr));
        edit_button_1->setText(QCoreApplication::translate("centralwidget", "Mountain", nullptr));
        edit_button_2->setText(QCoreApplication::translate("centralwidget", "Sand", nullptr));
        edit_button_3->setText(QCoreApplication::translate("centralwidget", "Rock", nullptr));
        building_button->setText(QCoreApplication::translate("centralwidget", "Building", nullptr));
        save_button->setText(QCoreApplication::translate("centralwidget", "Save", nullptr));
        (void)centralwidget;
    } // retranslateUi

};

namespace Ui {
    class centralwidget: public Ui_centralwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAP_H
