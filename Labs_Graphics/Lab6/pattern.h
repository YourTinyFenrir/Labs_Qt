#ifndef PATTERN_H
#define PATTERN_H

#include <QWidget>
#include <QPen>
#include <data.h>

class Pattern : public QWidget
{
    Q_OBJECT
public:
    explicit Pattern(QWidget *parent = nullptr);

public slots:
    void slot_updatePen(Data*); // Для обновления параметров пера

private:
    QPen pen; // Перо для рисования линии-образца

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // PATTERN_H
