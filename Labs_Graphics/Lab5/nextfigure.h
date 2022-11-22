#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include <figure.h>

class NextFigure : public QWidget
{
    Q_OBJECT
public:
    explicit NextFigure(QWidget *parent = nullptr);

public slots:
    void slot_setFigure(Figure* f) {
        figure = f;
        this->repaint(); // Выводим на экран новую фигуру
    };

private:
    Figure* figure;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // NEXTFIGURE_H
