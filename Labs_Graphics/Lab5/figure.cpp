#include "figure.h"
#include <QVector>
#include <QTime>

Figure::Figure(uint cs)
{
    cellSize = cs;
    curPos.setX(0);
    curPos.setY(0);

    arr[0] = arr[1] = arr[2] = Qt::black;
}

void Figure::rotateColors(bool dir)
{
    if (dir) { // Направление - вверх
        QColor temp = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[0];
        arr[0] = temp;
    }
    else { // Направление - вниз
        QColor temp = arr[0];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = temp;
    }
}

void Figure::makeRandomColors()
{
    QColor colorPool[] {Qt::red, Qt::blue, Qt::green, Qt::yellow, Qt::cyan, Qt::darkYellow }; // Набор доступных цветов

    // Случайно выбираем цвета из набора
    QTime midnight(0, 0, 0);
    qsrand(midnight.msecsTo(QTime::currentTime()));

    for (int i = 0; i < 3; ++i) {
        arr[i] = colorPool[qrand() % 6];
    }
}
