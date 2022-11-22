#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QPixmap>

class MyPicture : public QWidget
{
    Q_OBJECT
public:
    explicit MyPicture(QWidget *parent = nullptr);

private slots:
    void scaleChanged(int); // Слот для изменения масштаба

private:
    QPixmap pixmap;
    int scale;

protected:
    void paintEvent(QPaintEvent*);
};

#endif // MYPICTURE_H
