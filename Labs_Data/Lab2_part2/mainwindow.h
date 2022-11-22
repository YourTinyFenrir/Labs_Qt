#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <databasecontroller.h>

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
    void on_action_createTables_triggered() { dbc->createTables(); };
    void on_action_createModels_triggered();
    void on_action_DoQuery_triggered();

private:
    Ui::MainWindow *ui;

    DataBaseController* dbc;
};
#endif // MAINWINDOW_H
