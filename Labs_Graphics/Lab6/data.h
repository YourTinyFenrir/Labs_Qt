#ifndef DATA_H
#define DATA_H

#include "QColor"

struct Data // Структура для передачи данных между виджетами
{
public:
    Data() {};
    Data(QColor, qreal, Qt::PenStyle);

    QColor color; //  Цвет пера
    qreal width; // Толщина пера
    Qt::PenStyle penStyle; // Стиль пера
};

#endif // DATA_H
