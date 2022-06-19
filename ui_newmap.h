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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *create_box;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *map_size;
    QSpinBox *x;
    QSpinBox *y;
    QLabel *label_3;
    QSpinBox *num_players;
    QPushButton *create_button;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *open_box;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *filename;
    QSpacerItem *verticalSpacer;
    QPushButton *open_button;

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
        verticalLayoutWidget->setGeometry(QRect(190, 110, 126, 230));
        create_box = new QVBoxLayout(verticalLayoutWidget);
        create_box->setObjectName(QString::fromUtf8("create_box"));
        create_box->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        create_box->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        create_box->addWidget(label_2);

        map_size = new QHBoxLayout();
        map_size->setObjectName(QString::fromUtf8("map_size"));
        x = new QSpinBox(verticalLayoutWidget);
        x->setObjectName(QString::fromUtf8("x"));

        map_size->addWidget(x);

        y = new QSpinBox(verticalLayoutWidget);
        y->setObjectName(QString::fromUtf8("y"));

        map_size->addWidget(y);


        create_box->addLayout(map_size);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        create_box->addWidget(label_3);

        num_players = new QSpinBox(verticalLayoutWidget);
        num_players->setObjectName(QString::fromUtf8("num_players"));

        create_box->addWidget(num_players);

        create_button = new QPushButton(verticalLayoutWidget);
        create_button->setObjectName(QString::fromUtf8("create_button"));

        create_box->addWidget(create_button);

        verticalLayoutWidget_2 = new QWidget(widget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(410, 109, 127, 231));
        open_box = new QVBoxLayout(verticalLayoutWidget_2);
        open_box->setObjectName(QString::fromUtf8("open_box"));
        open_box->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        open_box->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        open_box->addWidget(label_5);

        filename = new QLineEdit(verticalLayoutWidget_2);
        filename->setObjectName(QString::fromUtf8("filename"));

        open_box->addWidget(filename);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        open_box->addItem(verticalSpacer);

        open_button = new QPushButton(verticalLayoutWidget_2);
        open_button->setObjectName(QString::fromUtf8("open_button"));

        open_box->addWidget(open_button);


        verticalLayout->addWidget(widget);

        NewMap->setCentralWidget(centralwidget);

        retranslateUi(NewMap);

        QMetaObject::connectSlotsByName(NewMap);
    } // setupUi

    void retranslateUi(QMainWindow *NewMap)
    {
        NewMap->setWindowTitle(QCoreApplication::translate("NewMap", "New Map", nullptr));
        label->setText(QCoreApplication::translate("NewMap", "create new map", nullptr));
        label_2->setText(QCoreApplication::translate("NewMap", "map size", nullptr));
        label_3->setText(QCoreApplication::translate("NewMap", "number of players", nullptr));
        create_button->setText(QCoreApplication::translate("NewMap", "Create", nullptr));
        label_4->setText(QCoreApplication::translate("NewMap", "open existing map", nullptr));
        label_5->setText(QCoreApplication::translate("NewMap", "enter filename:", nullptr));
        open_button->setText(QCoreApplication::translate("NewMap", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewMap: public Ui_NewMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAP_H
