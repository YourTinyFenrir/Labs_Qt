#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"
#include "data.h"

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
    void on_pb_ellipse_clicked();
    void on_pb_rectangle_clicked();
    void slot_addItem(MyScene::shapeType shapeType, QRectF rect, Data* data); // Слот для добавления фигуры в tableWidget

    // Слоты для трансформации примитивов
    void slot_rotate(int);
    void slot_scaleX(double);
    void slot_scaleY(double);
    void slot_shearX(double);
    void slot_shearY(double);

private:
    Ui::MainWindow *ui;
    MyScene* ms; // Сцена для рисования примитивов
    int pastAngle; // Для поворота относительно начального расположения

    // Для масштабирования относительно начальных размеров
    double pastScaleX;
    double pastScaleY;

    // Для скоса относительно начального наклона
    double pastShearX;
    double pastShearY;
};
#endif // MAINWINDOW_H
