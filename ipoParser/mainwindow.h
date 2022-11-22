#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QHash>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readFile(QString); // Читает данные из файла, сохраняет построчно в QVector

private slots:
    void on_pb_file_clicked();
    void on_pb_folder_clicked();
    void on_pb_start_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> sourceFile; // Обрабатываемый файл в виде массива строк
    QHash<QString, QString> hashTable; // Комбинации (Контрольная сумма; Идентификатор) из ipo-фвйла
    double progressCount; // Счетчик для Progress bar

};
#endif // MAINWINDOW_H
