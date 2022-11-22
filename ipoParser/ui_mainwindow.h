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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *filePath;
    QPushButton *pb_file;
    QHBoxLayout *horizontalLayout_2;
    QLabel *folderPath;
    QPushButton *pb_folder;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QProgressBar *progressBar;
    QPushButton *pb_start;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(735, 579);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        filePath = new QLabel(centralwidget);
        filePath->setObjectName(QString::fromUtf8("filePath"));
        filePath->setMinimumSize(QSize(400, 0));

        horizontalLayout->addWidget(filePath);

        pb_file = new QPushButton(centralwidget);
        pb_file->setObjectName(QString::fromUtf8("pb_file"));
        pb_file->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(pb_file);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        folderPath = new QLabel(centralwidget);
        folderPath->setObjectName(QString::fromUtf8("folderPath"));
        folderPath->setMinimumSize(QSize(400, 0));

        horizontalLayout_2->addWidget(folderPath);

        pb_folder = new QPushButton(centralwidget);
        pb_folder->setObjectName(QString::fromUtf8("pb_folder"));
        pb_folder->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pb_folder);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_3->addWidget(progressBar);

        pb_start = new QPushButton(centralwidget);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_start->sizePolicy().hasHeightForWidth());
        pb_start->setSizePolicy(sizePolicy);
        pb_start->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_3->addWidget(pb_start);


        verticalLayout_2->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 735, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\321\213\321\205 \321\201\321\203\320\274\320\274", nullptr));
        filePath->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pb_file->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        folderPath->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pb_folder->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\320\277\320\272\320\260", nullptr));
        pb_start->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
