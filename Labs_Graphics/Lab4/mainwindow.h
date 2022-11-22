#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>
#include "mypicture.h"

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

    // Слоты для перевода числовых данных в строковые и наоборот
    void slot_setInt(QString);
    void slot_setStr(int);

    void slot_showScale(int); // Слот для отображения масштаба в статусбаре

    void on_action_About_triggered();

    void wheelHasSpinned(bool); // Слот для фиксации прокрутки колесика мыши

private:
    Ui::MainWindow *ui;
    QValidator* valid; // Валидатор для lineEdit
    MyPicture mp; // Для отображения картинки

protected:
    void wheelEvent(QWheelEvent*);
};
#endif // MAINWINDOW_H
