#include "myrect.h"

void MyRect::drawRect(QPainter& p)
{
    p.setPen(m_pen);
    p.setBrush(QBrush()); // Не закрашиваем
    p.drawRect(m_rect);
}

void MyRect::drawCurrentRect(QPainter& p)
{
    p.setPen(m_pen);
    p.setBrush(QBrush(Qt::gray)); // Закрашиваем
    p.drawRect(m_rect);
}
