#include "mypicture.h"
#include <QPainter>

MyPicture::MyPicture(QWidget *parent) : QWidget(parent)
{
    pixmap.load(":/Pictures/Images/Koala.jpg");
    scale = 100;
}

void MyPicture::scaleChanged(int sc)
{
    scale = sc;
    this->repaint();
}

void MyPicture::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    // Масштабируем картинку
    QRectF src(0.0, 0.0, pixmap.width() * scale / 100, pixmap.height() * scale / 100); // Изменяем размер картинки
    QRectF target(0.0, 0.0, this->width() * scale / 100, this->height() * scale / 100); // Изменяем размер области размещения картинки
    painter.drawPixmap(target, pixmap, src);

}
