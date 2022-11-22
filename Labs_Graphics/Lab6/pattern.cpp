#include "pattern.h"
#include "QPainter"

Pattern::Pattern(QWidget *parent) : QWidget(parent)
{

}

void Pattern::slot_updatePen(Data* d)
{
    // Устанавливаем параметры пера исходя из данных, введенных пользователем
    pen.setColor(d->color);
    pen.setWidth(d->width);
    pen.setStyle(d->penStyle);

    this->repaint();
}

void Pattern::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setPen(pen); // Устанавливаем перо
    painter.drawLine(0, 0, this->size().width(), this->size().height()); // Рисуем линию
}
