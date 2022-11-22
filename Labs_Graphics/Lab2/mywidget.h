#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QVector>
#include <QRect>
#include <QPainter>
#include <QCursor>
#include <QPixmap>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void setPixCursor(QPixmap); // Установка курсора в виде картинки

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void timerEvent(QTimerEvent *);

private:
    int drawingType; // Тип действия с областью изображения (0 - очистка, 1 - центр паутины, 2 - сетка паутины, 3 - движение паучка)
    QPoint center; // Центр паутинки
    QPoint rectTop; // Вершина прямоугольника
    QVector<QRect> rcts; // Сетка паутины из прямоугольников
    QCursor* cur; // Курсор
    bool isRunning; // Движется ли паучок
    int timerId; // ID таймера
    QPoint curPos; // Текущая позиция движения паучка
    QVector<QPoint> pts; // Точки, по которым движется паучок
    bool horizDir; // Направление движения по горизонтали (0 - влево, 1 - вправо)
    bool vertDir; // Направление движения по вертикали (0 - вверх, 1 - вниз)
};

#endif // MYWIDGET_H
