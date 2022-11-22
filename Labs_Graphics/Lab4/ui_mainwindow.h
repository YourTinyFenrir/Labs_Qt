/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mypicture.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Exit;
    QAction *action_About;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QLabel *label_spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QLabel *label_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QSlider *hSlider;
    QLabel *label_hSlider;
    QPushButton *button_exit;
    MyPicture *widget;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Info;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(812, 550);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Images/icon1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action_Exit->setCheckable(true);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setValue(0);

        horizontalLayout->addWidget(spinBox);

        label_spinBox = new QLabel(centralwidget);
        label_spinBox->setObjectName(QString::fromUtf8("label_spinBox"));
        label_spinBox->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label_spinBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        label_lineEdit = new QLabel(centralwidget);
        label_lineEdit->setObjectName(QString::fromUtf8("label_lineEdit"));
        label_lineEdit->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label_lineEdit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        hSlider = new QSlider(centralwidget);
        hSlider->setObjectName(QString::fromUtf8("hSlider"));
        hSlider->setOrientation(Qt::Horizontal);
        hSlider->setTickPosition(QSlider::TicksAbove);
        hSlider->setTickInterval(10);

        horizontalLayout_4->addWidget(hSlider);

        label_hSlider = new QLabel(centralwidget);
        label_hSlider->setObjectName(QString::fromUtf8("label_hSlider"));
        label_hSlider->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_hSlider);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 2);

        button_exit = new QPushButton(centralwidget);
        button_exit->setObjectName(QString::fromUtf8("button_exit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/Images/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        button_exit->setIcon(icon1);

        gridLayout->addWidget(button_exit, 0, 1, 1, 1);

        widget = new MyPicture(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(450, 300));

        gridLayout->addWidget(widget, 3, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 812, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Info = new QMenu(menubar);
        menu_Info->setObjectName(QString::fromUtf8("menu_Info"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label_spinBox->setBuddy(spinBox);
        label_lineEdit->setBuddy(lineEdit);
        label_hSlider->setBuddy(hSlider);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Info->menuAction());
        menu_File->addAction(action_Exit);
        menu_Info->addAction(action_About);

        retranslateUi(MainWindow);
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), hSlider, SLOT(setValue(int)));
        QObject::connect(hSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), MainWindow, SLOT(slot_setInt(QString)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), MainWindow, SLOT(slot_setStr(int)));
        QObject::connect(hSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(slot_setStr(int)));
        QObject::connect(hSlider, SIGNAL(valueChanged(int)), widget, SLOT(scaleChanged(int)));
        QObject::connect(action_Exit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(button_exit, SIGNAL(clicked()), action_Exit, SLOT(trigger()));
        QObject::connect(hSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(slot_showScale(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Designer", nullptr));
#if QT_CONFIG(statustip)
        MainWindow->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        action_Exit->setText(QCoreApplication::translate("MainWindow", "&\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(tooltip)
        action_Exit->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        action_Exit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        action_About->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_spinBox->setText(QCoreApplication::translate("MainWindow", "&BoxBuddy", nullptr));
        label_lineEdit->setText(QCoreApplication::translate("MainWindow", "&LineEditBuddy", nullptr));
#if QT_CONFIG(tooltip)
        hSlider->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_hSlider->setText(QCoreApplication::translate("MainWindow", "&SliderBuddy", nullptr));
        button_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&\320\244\320\260\320\271\320\273", nullptr));
        menu_Info->setTitle(QCoreApplication::translate("MainWindow", "&\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
