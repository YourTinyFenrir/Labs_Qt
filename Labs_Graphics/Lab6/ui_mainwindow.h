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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_chooseColor;
    QAction *action_settings;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QGraphicsView *gv_left;
    QGraphicsView *gv_right;
    QVBoxLayout *verticalLayout_2;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_5;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *sb_angle;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_6;
    QLabel *label_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *sb_scaleX;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *sb_scaleY;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_7;
    QLabel *label_6;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QDoubleSpinBox *sb_shearX;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QDoubleSpinBox *sb_shearY;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_ellipse;
    QPushButton *pb_rectangle;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1250, 780);
        action_chooseColor = new QAction(MainWindow);
        action_chooseColor->setObjectName(QString::fromUtf8("action_chooseColor"));
        action_settings = new QAction(MainWindow);
        action_settings->setObjectName(QString::fromUtf8("action_settings"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        gv_left = new QGraphicsView(splitter);
        gv_left->setObjectName(QString::fromUtf8("gv_left"));
        gv_left->setMinimumSize(QSize(0, 0));
        splitter->addWidget(gv_left);
        gv_right = new QGraphicsView(splitter);
        gv_right->setObjectName(QString::fromUtf8("gv_right"));
        gv_right->setMinimumSize(QSize(0, 0));
        splitter->addWidget(gv_right);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dockWidget = new QDockWidget(centralwidget);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy1);
        dockWidget->setMinimumSize(QSize(100, 35));
        dockWidget->setMaximumSize(QSize(200, 524287));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        label = new QLabel(dockWidgetContents_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 81, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        widget = new QWidget(dockWidgetContents_5);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 60, 171, 31));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        sb_angle = new QSpinBox(widget);
        sb_angle->setObjectName(QString::fromUtf8("sb_angle"));
        sb_angle->setMaximum(360);

        horizontalLayout_3->addWidget(sb_angle);

        dockWidget->setWidget(dockWidgetContents_5);

        verticalLayout_2->addWidget(dockWidget);

        dockWidget_2 = new QDockWidget(centralwidget);
        dockWidget_2->setObjectName(QString::fromUtf8("dockWidget_2"));
        sizePolicy1.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy1);
        dockWidget_2->setMinimumSize(QSize(100, 0));
        dockWidget_2->setMaximumSize(QSize(200, 524287));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QString::fromUtf8("dockWidgetContents_6"));
        label_3 = new QLabel(dockWidgetContents_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 20, 71, 21));
        label_3->setFont(font);
        widget1 = new QWidget(dockWidgetContents_6);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 60, 179, 71));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        sb_scaleX = new QDoubleSpinBox(widget1);
        sb_scaleX->setObjectName(QString::fromUtf8("sb_scaleX"));
        sb_scaleX->setMinimum(0.000000000000000);
        sb_scaleX->setSingleStep(0.100000000000000);
        sb_scaleX->setValue(1.000000000000000);

        horizontalLayout_4->addWidget(sb_scaleX);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        sb_scaleY = new QDoubleSpinBox(widget1);
        sb_scaleY->setObjectName(QString::fromUtf8("sb_scaleY"));
        sb_scaleY->setMinimum(0.000000000000000);
        sb_scaleY->setSingleStep(0.100000000000000);
        sb_scaleY->setValue(1.000000000000000);

        horizontalLayout_5->addWidget(sb_scaleY);


        verticalLayout_3->addLayout(horizontalLayout_5);

        dockWidget_2->setWidget(dockWidgetContents_6);

        verticalLayout_2->addWidget(dockWidget_2);

        dockWidget_3 = new QDockWidget(centralwidget);
        dockWidget_3->setObjectName(QString::fromUtf8("dockWidget_3"));
        sizePolicy.setHeightForWidth(dockWidget_3->sizePolicy().hasHeightForWidth());
        dockWidget_3->setSizePolicy(sizePolicy);
        dockWidget_3->setMinimumSize(QSize(100, 35));
        dockWidget_3->setMaximumSize(QSize(200, 524287));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QString::fromUtf8("dockWidgetContents_7"));
        label_6 = new QLabel(dockWidgetContents_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 20, 47, 14));
        label_6->setFont(font);
        widget2 = new QWidget(dockWidgetContents_7);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(20, 60, 181, 71));
        verticalLayout_4 = new QVBoxLayout(widget2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_6->addWidget(label_7);

        sb_shearX = new QDoubleSpinBox(widget2);
        sb_shearX->setObjectName(QString::fromUtf8("sb_shearX"));
        sb_shearX->setSingleStep(0.100000000000000);
        sb_shearX->setValue(0.000000000000000);

        horizontalLayout_6->addWidget(sb_shearX);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(widget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_7->addWidget(label_8);

        sb_shearY = new QDoubleSpinBox(widget2);
        sb_shearY->setObjectName(QString::fromUtf8("sb_shearY"));
        sb_shearY->setSingleStep(0.100000000000000);
        sb_shearY->setValue(0.000000000000000);

        horizontalLayout_7->addWidget(sb_shearY);


        verticalLayout_4->addLayout(horizontalLayout_7);

        dockWidget_3->setWidget(dockWidgetContents_7);

        verticalLayout_2->addWidget(dockWidget_3);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_ellipse = new QPushButton(centralwidget);
        pb_ellipse->setObjectName(QString::fromUtf8("pb_ellipse"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/IconEllipse.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pb_ellipse->setIcon(icon);
        pb_ellipse->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pb_ellipse);

        pb_rectangle = new QPushButton(centralwidget);
        pb_rectangle->setObjectName(QString::fromUtf8("pb_rectangle"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/IconRect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pb_rectangle->setIcon(icon1);
        pb_rectangle->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pb_rectangle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setColumnCount(5);

        gridLayout->addWidget(tableWidget, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1250, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_chooseColor);
        menu->addAction(action_settings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_chooseColor->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        action_settings->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\201", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        pb_ellipse->setText(QString());
        pb_rectangle->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\204\320\270\320\263\321\203\321\200\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\270\320\273\321\214 \320\277\320\265\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\277\320\265\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\277\320\265\321\200\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
