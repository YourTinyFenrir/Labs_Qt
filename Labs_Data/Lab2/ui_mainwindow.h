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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "drawsimple.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_createConnection;
    QAction *action_closeConnection;
    QAction *action_createTable;
    QAction *action_insertInto;
    QAction *action_printTable;
    QAction *action_dropTable;
    QAction *action_initTableModel;
    QAction *action_selectTable;
    QAction *action_insertRows;
    QAction *action_removeRows;
    QAction *action_doQuery;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTableView *tableView;
    DrawSimple *drawView;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action_createConnection = new QAction(MainWindow);
        action_createConnection->setObjectName(QString::fromUtf8("action_createConnection"));
        action_closeConnection = new QAction(MainWindow);
        action_closeConnection->setObjectName(QString::fromUtf8("action_closeConnection"));
        action_createTable = new QAction(MainWindow);
        action_createTable->setObjectName(QString::fromUtf8("action_createTable"));
        action_insertInto = new QAction(MainWindow);
        action_insertInto->setObjectName(QString::fromUtf8("action_insertInto"));
        action_printTable = new QAction(MainWindow);
        action_printTable->setObjectName(QString::fromUtf8("action_printTable"));
        action_dropTable = new QAction(MainWindow);
        action_dropTable->setObjectName(QString::fromUtf8("action_dropTable"));
        action_initTableModel = new QAction(MainWindow);
        action_initTableModel->setObjectName(QString::fromUtf8("action_initTableModel"));
        action_selectTable = new QAction(MainWindow);
        action_selectTable->setObjectName(QString::fromUtf8("action_selectTable"));
        action_insertRows = new QAction(MainWindow);
        action_insertRows->setObjectName(QString::fromUtf8("action_insertRows"));
        action_removeRows = new QAction(MainWindow);
        action_removeRows->setObjectName(QString::fromUtf8("action_removeRows"));
        action_doQuery = new QAction(MainWindow);
        action_doQuery->setObjectName(QString::fromUtf8("action_doQuery"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        splitter->addWidget(tableView);
        drawView = new DrawSimple(splitter);
        drawView->setObjectName(QString::fromUtf8("drawView"));
        splitter->addWidget(drawView);

        horizontalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action_createConnection);
        menu->addAction(action_closeConnection);
        menu->addAction(action_createTable);
        menu->addAction(action_insertInto);
        menu->addAction(action_printTable);
        menu->addAction(action_dropTable);
        menu_2->addAction(action_initTableModel);
        menu_2->addAction(action_selectTable);
        menu_2->addAction(action_insertRows);
        menu_2->addAction(action_removeRows);
        menu_3->addAction(action_doQuery);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_createConnection->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        action_closeConnection->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        action_createTable->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        action_insertInto->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        action_printTable->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        action_dropTable->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        action_initTableModel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        action_selectTable->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        action_insertRows->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        action_removeRows->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        action_doQuery->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\221\320\224", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
