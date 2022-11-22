#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QSharedMemory>

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
    void on_pb_start_clicked();
    void on_pb_kill_clicked();
    void on_pb_startDetached_clicked();
    void on_pb_startDetachedParams_clicked();
    void on_pb_execute_clicked();
    void on_pb_executeParams_clicked();
    void on_pb_toChild_clicked();

    void afterStart();
    void afterError(QProcess::ProcessError);
    void afterFinish(int, QProcess::ExitStatus);
    void readFromChild();

    void on_pb_createShared_clicked();
    void on_pb_writeShared_clicked();
    void on_pb_readShared_clicked();

private:
    Ui::MainWindow *ui;
    QProcess* proc;
    QSharedMemory* memory;
};
#endif // MAINWINDOW_H
