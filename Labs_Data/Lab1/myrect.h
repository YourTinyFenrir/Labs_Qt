#ifndef MYRECT_H
#define MYRECT_H

#include "QPen"
#include "QRect"
#include "QPainter"


class MyRect
{
public:
    MyRect() {};
    MyRect(QPen p, QRect r) { m_pen = p; m_rect = r; };

    // Сеттер для прямоугольника и пера
    void setMyRect(MyRect mr) { m_pen = mr.pen();
                                m_rect = mr.rect(); };

    // Геттеры/сеттеры пера
    QPen pen() { return m_pen; };

    QColor penColor() { return m_pen.color(); } ;
    Qt::PenStyle penStyle() { return m_pen.style(); };
    qreal penWidth() { return m_pen.width(); };

    void setPen(QPen p) { m_pen = p; };
    void setPenColor(QColor c) { m_pen.setColor(c); };
    void setPenStyle(Qt::PenStyle ps) { m_pen.setStyle(ps); };
    void setPenWidth(qreal w) { m_pen.setWidth(w); };

    // Геттеры/сеттеры прямоугольника
    QRect rect() { return m_rect; };

    int rectLeft() { return m_rect.left(); };
    int rectTop() { return m_rect.top(); };
    int rectWidth() { return m_rect.width(); };
    int rectHeight() { return m_rect.height(); };

    // При изменении координаты вершины изменяется высота/ширина - почему????!!

    void setRect(QRect r) { m_rect = r; };
    void setRectLeft(int l) { m_rect.setLeft(l); };
    void setRectTop(int t) { m_rect.setTop(t); };
    void setRectWidth(int w) { m_rect.setWidth(w); };
    void setRectHeight(int h) { m_rect.setHeight(h); };

    void drawRect(QPainter&); // Нарисовать прямоугольник
    void drawCurrentRect(QPainter&);  // Нарисовать закрашенный прямоугольник

private:
    QPen m_pen; // Кисть, которой изображается прямоугольник
    QRect m_rect; // Прямоугольник
};

#endif // MYRECT_H
