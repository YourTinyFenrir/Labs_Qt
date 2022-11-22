#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasecontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_createConnection_triggered() { dbc->createConnection(); };
    void on_action_closeConnection_triggered() { dbc->closeConnection(); };
    void on_action_createTable_triggered() { dbc->createTable(); };
    void on_action_dropTable_triggered() { dbc->dropTable(); };
    void on_action_insertInto_triggered() { dbc->insertInto(); };
    void on_action_printTable_triggered() { dbc->printTable(); };
    void on_action_initTableModel_triggered();
    void on_action_doQuery_triggered() { dbc->doQuery(); };
    void on_action_selectTable_triggered();
    void on_action_insertRows_triggered();
    void on_action_removeRows_triggered();

    void slot_getData(MyRect);

private:
    Ui::MainWindow *ui;
    DataBaseController* dbc;
    QSqlTableModel* model;
};
#endif // MAINWINDOW_H
