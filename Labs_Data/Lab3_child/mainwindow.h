#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_pb_send_clicked();
    void on_pb_receive_clicked();
    void on_pb_attach_clicked();
    void on_pb_readShared_clicked();
    void on_pb_writeShared_clicked();

private:
    Ui::MainWindow *ui;
    QSharedMemory* memory;
};
#endif // MAINWINDOW_H
