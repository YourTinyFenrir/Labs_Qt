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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *le_msgTo;
    QPushButton *pb_send;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_receive;
    QLineEdit *le_msgFrom;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPushButton *pb_attach;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pb_readShared;
    QPushButton *pb_writeShared;
    QVBoxLayout *verticalLayout;
    QLineEdit *le_readShared;
    QLineEdit *le_writeShared;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(459, 381);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));

        verticalLayout_5->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        le_msgTo = new QLineEdit(centralwidget);
        le_msgTo->setObjectName(QString::fromUtf8("le_msgTo"));

        horizontalLayout_3->addWidget(le_msgTo);

        pb_send = new QPushButton(centralwidget);
        pb_send->setObjectName(QString::fromUtf8("pb_send"));

        horizontalLayout_3->addWidget(pb_send);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));

        verticalLayout_4->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pb_receive = new QPushButton(centralwidget);
        pb_receive->setObjectName(QString::fromUtf8("pb_receive"));

        horizontalLayout_2->addWidget(pb_receive);

        le_msgFrom = new QLineEdit(centralwidget);
        le_msgFrom->setObjectName(QString::fromUtf8("le_msgFrom"));
        le_msgFrom->setEnabled(false);

        horizontalLayout_2->addWidget(le_msgFrom);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalSpacer = new QSpacerItem(20, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 20));

        verticalLayout_3->addWidget(label_3);

        pb_attach = new QPushButton(centralwidget);
        pb_attach->setObjectName(QString::fromUtf8("pb_attach"));

        verticalLayout_3->addWidget(pb_attach);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pb_readShared = new QPushButton(centralwidget);
        pb_readShared->setObjectName(QString::fromUtf8("pb_readShared"));

        verticalLayout_2->addWidget(pb_readShared);

        pb_writeShared = new QPushButton(centralwidget);
        pb_writeShared->setObjectName(QString::fromUtf8("pb_writeShared"));

        verticalLayout_2->addWidget(pb_writeShared);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        le_readShared = new QLineEdit(centralwidget);
        le_readShared->setObjectName(QString::fromUtf8("le_readShared"));
        le_readShared->setEnabled(false);

        verticalLayout->addWidget(le_readShared);

        le_writeShared = new QLineEdit(centralwidget);
        le_writeShared->setObjectName(QString::fromUtf8("le_writeShared"));

        verticalLayout->addWidget(le_writeShared);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 459, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        pb_send->setText(QCoreApplication::translate("MainWindow", "Send to parent", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        pb_receive->setText(QCoreApplication::translate("MainWindow", "Receive from parent", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Shared memory", nullptr));
        pb_attach->setText(QCoreApplication::translate("MainWindow", "Attach to shared", nullptr));
        pb_readShared->setText(QCoreApplication::translate("MainWindow", "Read from shared", nullptr));
        pb_writeShared->setText(QCoreApplication::translate("MainWindow", "Write to shared", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
