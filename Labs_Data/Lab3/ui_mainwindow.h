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
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *le_name;
    QLineEdit *le_params;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QPushButton *pb_startDetached;
    QPushButton *pb_startDetachedParams;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_8;
    QPushButton *pb_execute;
    QPushButton *pb_executeParams;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QPushButton *pb_start;
    QPushButton *pb_kill;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *le_exitCode;
    QLineEdit *le_exitStatus;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_10;
    QPushButton *pb_toChild;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *le_fromChild;
    QLineEdit *le_toChild;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_11;
    QPushButton *pb_createShared;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_13;
    QPushButton *pb_writeShared;
    QPushButton *pb_readShared;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *le_writeShared;
    QLineEdit *le_readShared;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(902, 548);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        le_name = new QLineEdit(centralwidget);
        le_name->setObjectName(QString::fromUtf8("le_name"));
        le_name->setMinimumSize(QSize(300, 0));

        verticalLayout->addWidget(le_name);

        le_params = new QLineEdit(centralwidget);
        le_params->setObjectName(QString::fromUtf8("le_params"));

        verticalLayout->addWidget(le_params);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_16->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 20));

        verticalLayout_8->addWidget(label_7);

        pb_startDetached = new QPushButton(centralwidget);
        pb_startDetached->setObjectName(QString::fromUtf8("pb_startDetached"));

        verticalLayout_8->addWidget(pb_startDetached);

        pb_startDetachedParams = new QPushButton(centralwidget);
        pb_startDetachedParams->setObjectName(QString::fromUtf8("pb_startDetachedParams"));

        verticalLayout_8->addWidget(pb_startDetachedParams);


        verticalLayout_16->addLayout(verticalLayout_8);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777215, 20));

        verticalLayout_9->addWidget(label_8);

        pb_execute = new QPushButton(centralwidget);
        pb_execute->setObjectName(QString::fromUtf8("pb_execute"));

        verticalLayout_9->addWidget(pb_execute);

        pb_executeParams = new QPushButton(centralwidget);
        pb_executeParams->setObjectName(QString::fromUtf8("pb_executeParams"));

        verticalLayout_9->addWidget(pb_executeParams);


        verticalLayout_16->addLayout(verticalLayout_9);


        horizontalLayout_5->addLayout(verticalLayout_16);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 20));

        verticalLayout_6->addWidget(label_4);

        pb_start = new QPushButton(centralwidget);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));

        verticalLayout_6->addWidget(pb_start);

        pb_kill = new QPushButton(centralwidget);
        pb_kill->setObjectName(QString::fromUtf8("pb_kill"));

        verticalLayout_6->addWidget(pb_kill);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_5->addWidget(label_5);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        le_exitCode = new QLineEdit(centralwidget);
        le_exitCode->setObjectName(QString::fromUtf8("le_exitCode"));
        le_exitCode->setEnabled(false);

        verticalLayout_4->addWidget(le_exitCode);

        le_exitStatus = new QLineEdit(centralwidget);
        le_exitStatus->setObjectName(QString::fromUtf8("le_exitStatus"));
        le_exitStatus->setEnabled(false);

        verticalLayout_4->addWidget(le_exitStatus);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_15->addLayout(verticalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_3);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(16777215, 20));

        verticalLayout_11->addWidget(label_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_10->addWidget(label_10);

        pb_toChild = new QPushButton(centralwidget);
        pb_toChild->setObjectName(QString::fromUtf8("pb_toChild"));

        verticalLayout_10->addWidget(pb_toChild);


        horizontalLayout_3->addLayout(verticalLayout_10);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        le_fromChild = new QLineEdit(centralwidget);
        le_fromChild->setObjectName(QString::fromUtf8("le_fromChild"));
        le_fromChild->setEnabled(false);

        verticalLayout_7->addWidget(le_fromChild);

        le_toChild = new QLineEdit(centralwidget);
        le_toChild->setObjectName(QString::fromUtf8("le_toChild"));

        verticalLayout_7->addWidget(le_toChild);


        horizontalLayout_3->addLayout(verticalLayout_7);


        verticalLayout_11->addLayout(horizontalLayout_3);


        verticalLayout_15->addLayout(verticalLayout_11);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_4);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 20));

        verticalLayout_14->addWidget(label_11);

        pb_createShared = new QPushButton(centralwidget);
        pb_createShared->setObjectName(QString::fromUtf8("pb_createShared"));

        verticalLayout_14->addWidget(pb_createShared);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        pb_writeShared = new QPushButton(centralwidget);
        pb_writeShared->setObjectName(QString::fromUtf8("pb_writeShared"));

        verticalLayout_13->addWidget(pb_writeShared);

        pb_readShared = new QPushButton(centralwidget);
        pb_readShared->setObjectName(QString::fromUtf8("pb_readShared"));

        verticalLayout_13->addWidget(pb_readShared);


        horizontalLayout_4->addLayout(verticalLayout_13);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        le_writeShared = new QLineEdit(centralwidget);
        le_writeShared->setObjectName(QString::fromUtf8("le_writeShared"));

        verticalLayout_12->addWidget(le_writeShared);

        le_readShared = new QLineEdit(centralwidget);
        le_readShared->setObjectName(QString::fromUtf8("le_readShared"));
        le_readShared->setEnabled(false);

        verticalLayout_12->addWidget(le_readShared);


        horizontalLayout_4->addLayout(verticalLayout_12);


        verticalLayout_14->addLayout(horizontalLayout_4);


        verticalLayout_15->addLayout(verticalLayout_14);


        horizontalLayout_5->addLayout(verticalLayout_15);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 902, 21));
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
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\267\320\260\320\277\321\203\321\201\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "params", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "detached process", nullptr));
        pb_startDetached->setText(QCoreApplication::translate("MainWindow", "startDetached", nullptr));
        pb_startDetachedParams->setText(QCoreApplication::translate("MainWindow", "startDetached + Params", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265 \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\270\321\217", nullptr));
        pb_execute->setText(QCoreApplication::translate("MainWindow", "execute", nullptr));
        pb_executeParams->setText(QCoreApplication::translate("MainWindow", "execute + Params", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\276\321\207\320\265\321\200\320\275\320\270\320\274\320\270 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\260\320\274\320\270", nullptr));
        pb_start->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        pb_kill->setText(QCoreApplication::translate("MainWindow", "kill", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "ExitCode", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "ExitStatus", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\274\320\265\320\275 \320\264\320\260\320\275\320\275\321\213\320\274\320\270 \321\201 \320\264\320\276\321\207\320\265\321\200\320\275\320\270\320\274 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\276\320\274", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\265\320\274 \320\264\320\260\320\275\320\275\321\213\321\205 \320\276\321\202 \320\264\320\276\321\207\320\265\321\200\320\275\320\265\320\263\320\276", nullptr));
        pb_toChild->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\264\320\276\321\207\320\265\321\200\320\275\320\265\320\274\321\203", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Shared memory", nullptr));
        pb_createShared->setText(QCoreApplication::translate("MainWindow", "Create shared memory", nullptr));
        pb_writeShared->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        pb_readShared->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
