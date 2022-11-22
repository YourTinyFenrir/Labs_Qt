#include "nextfigure.h"
#include "QPainter"

#include "QDebug"

NextFigure::NextFigure(QWidget *parent) : QWidget(parent)
{
    figure = new Figure(40);
}

void NextFigure::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    uint cellSize = figure->getCellSize();

    for (int i = 0; i < 3; ++i) {
        QBrush br(figure->getArr(i));

        // Выравниваем по центру виджета (ну почти))))
        QPoint leftUp(this->size().width() / 2 - cellSize / 2,
                      this->size().height() / 2 - i * cellSize);
        painter.fillRect(leftUp.x(), leftUp.y(), cellSize - 1, cellSize - 1, br); // Добавляем/убираем единицу для отображения сетки
    }
}
