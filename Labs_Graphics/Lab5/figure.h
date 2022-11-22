#ifndef FIGURE_H
#define FIGURE_H

#include "QColor"
#include "QPoint"
#include "QDebug"

class Figure
{
public:
    Figure() { }
    Figure(uint);

    void setCurrentPos(QPoint pt) { curPos = pt; } // Изменение положения фигуры
    QPoint getCurrentPos() { return curPos; } // Получение текущей позиции
    QColor getArr(int index) { // Получение части фигуры
        if (index >= 0 && index <= 2)
            return arr[index];
        else {
            qDebug() << "Выход за пределы массива";
            return QColor();
        }
    }

    uint getCellSize() { return cellSize; };

    void rotateColors(bool); // Изменение порядка элементов фигуры
    void makeRandomColors(); // Случайная генерация элементов фигуры

    // Перегрузка оператора присваивания
    Figure& operator= (Figure &f) {
        for (int i = 0; i < 3; i++) {
            this->arr[i] = f.arr[i];
        }
        this->curPos = f.curPos;
        this->cellSize = f.cellSize;
        return *this;
    }

private:
    QColor arr[3]; // Элементы, образующие фигуру (первый элементы - внизу)
    QPoint curPos; // Текущее положение фигуры на поле (по нижнему элементу)
    uint cellSize = 40; // Размер клетки
};

#endif // FIGURE_H
