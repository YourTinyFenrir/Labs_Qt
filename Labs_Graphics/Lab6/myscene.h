#ifndef MYSCENE_H
#define MYSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QAbstractGraphicsShapeItem>
#include <QColorDialog>

#include "data.h"
#include "dialog.h"

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QWidget *parent = nullptr);
    ~MyScene();

    enum shapeType {RECTANGLE, ELLIPSE}; // Виды фигуры, которые могут быть нарисованы

signals:
    void signal_newShape(MyScene::shapeType, QRectF, Data*); // Сигнал о добавлении новой фигуры

private:
    QAbstractGraphicsShapeItem* m_current; // Текущий рисуемый примитив
    bool m_drawingInProcess; // Идет ли процесс рисования
    QPointF m_startPoint; // Стартовая точка рисования (левый верхний угол)
    QRectF rect; // Вспомогательный прямоугольник для построения
    shapeType type; // Вид фигуры, которая сейчас рисуется

    Data* data; // Для обмена данными (QColor - цвет линий,
                //                     qreal - толщина линий,
                //                     Qt::penStyle - стиль)

public slots:
    void slot_chooseColor(); // Слот для смены цвета контуров
    void slot_settings(); // Слот для выбора настроек пера
    void slot_changeType(); // Слот для изменения типа рисуемой фигуры

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSCENE_H
