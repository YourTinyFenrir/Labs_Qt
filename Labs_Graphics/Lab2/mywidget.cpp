#include "mywidget.h"
#include "QDebug"
#include "QPalette"
#include "QMouseEvent"
#include "QInputEvent"
#include "QString"
#include "QToolTip"
#include "QPainter"
#include "QBrush"
#include "QBitmap"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    drawingType = 0;
    isRunning = false;

    // Изначально паучок движется вниз и вправо
    horizDir = true;
    vertDir = true;

    // Вывод в заголовок размеров окна
    this->setWindowTitle("Ширина - " + QString::number(this->size().width()) + ", длина - " + QString::number(this->size().height()));
}

MyWidget::~MyWidget()
{
    delete cur;
}

void MyWidget::setPixCursor(QPixmap pm)
{
    QBitmap bm(pm);
    pm.setMask(bm);
    cur = new QCursor(pm);
}

void MyWidget::mousePressEvent(QMouseEvent* ev)
{ 
    this->setCursor(*cur); // В процессе рисования отображается курсор с картинкой

    if (ev->button() == Qt::LeftButton) { // Если нажата левая кнопка мыши

        if (ev->modifiers().testFlag(Qt::ControlModifier)) { // С зажатым left ctrl

            // Передвижение паучка
            if (isRunning) { // Если уже движется
                killTimer(timerId); // Остановка таймера
                pts.clear(); // Очистка вектора точек траектории движения
                isRunning = false;
                this->unsetCursor(); // Смена курсора на дефолтный
            }
            else { // Если еще не двигается
                timerId = startTimer(1); // Запуск таймера
                curPos = ev->pos(); // Фиксация стартовой точки
                isRunning = true;
            }

            drawingType = 0; // Изменение состояния для paintEvent (Очистка экрана)

        }
        else { // без left ctrl
            drawingType = 1; // Изменение состояния для paintEvent (Рисуем перекрестие паутины)
            center = ev->pos(); // Фиксация центра паутины
        }

    }
    else if (ev->button() == Qt::RightButton) { // Если нажата правая кнопка мыши
        if (ev->modifiers().testFlag(Qt::ControlModifier)) { // С зажатым left ctrl

            // Вывод координат точки
            QString coord = "Координаты нажатия: (" + QString::number(ev->x()) + "; " + QString::number(ev->y()) + ")";
            QToolTip::showText(ev->pos(), coord);

            drawingType = 0; // Изменение состояния для paintEvent (Очистка экрана)

        }
        else { //
            drawingType = 2; // Изменение состояния для paintEvent (Рисуем сетку паутины)
            rectTop = ev->pos(); // Фиксирует первую вершину прямоугольника
        }
    }

    this->repaint();
}

void MyWidget::mouseReleaseEvent(QMouseEvent* ev)
{
    // Добавляем новый прямоугольник, перерисовываем сетку паутины
    if (drawingType == 2) {
        rcts.push_back(QRect(rectTop, ev->pos()));
        this->repaint();
    }

    this->unsetCursor(); // Процесс рисования завершен, возвращаем дефолтный курсор
}

void MyWidget::mouseMoveEvent(QMouseEvent* ev)
{
    QRect drawArea = this->rect(); // Координаты окна

    if (!drawArea.contains(ev->pos())) { // Если курсор вышел за пределы окна

        QPoint pt(ev->pos());

        // Проверка, за какую границу вышел курсор, и изменение координат, чтобы курсор остался в пределах окна
        if (ev->pos().x() <= drawArea.left())
            pt.setX(drawArea.left());
        if (ev->pos().x() >= drawArea.right())
            pt.setX(drawArea.right());
        if (ev->pos().y() <= drawArea.top())
            pt.setY(drawArea.top());
        if (ev->pos().y() >= drawArea.bottom())
            pt.setY(drawArea.bottom());

        this->cursor().setPos(this->mapToGlobal(pt)); // setPos принимается ГЛОБАЛЬНЫЕ координаты

    }

}

void MyWidget::paintEvent(QPaintEvent*)
{

    QPainter painter(this);

    // Рисование паутины
    if (drawingType == 1 || drawingType == 2) {

        QRect drawArea = this->rect();

        painter.setPen(Qt::red);
        painter.drawLine(drawArea.bottomLeft(), center);
        painter.drawLine(drawArea.bottomRight(), center);
        painter.drawLine(drawArea.topLeft(), center);
        painter.drawLine(drawArea.topRight(), center);

        painter.setPen(Qt::black);
        foreach (QRect r, rcts) {
            painter.drawRect(r);
        }

    }

    // Рисование траектории движения паучка
    else if (drawingType == 3) {

        if (pts.size() > 1) { // Соединяем соседние точки отрезками
            for (int i = 0; i < pts.size() - 1; ++i)
                painter.drawLine(pts[i], pts[i+1]);
        }

        painter.drawPixmap(curPos, cur->pixmap()); // Рисуем паучка в текущей точке

    }
    else { // Очистка вектора сетки паутины
        rcts.clear();
    }

}

void MyWidget::resizeEvent(QResizeEvent*)
{
    // Обновление заголовка при изменении размеров окна
    this->setWindowTitle("Ширина - " + QString::number(this->size().width()) + ", длина - " + QString::number(this->size().height()));
}

void MyWidget::timerEvent(QTimerEvent* ev)
{
    drawingType = 3; // Изменение состояния для paintEvent (Рисуем траекторию движения паучка)
    pts.push_back(curPos);

    const int step = 4; // Скорость движения паучка
    QPoint newPos(0, 0);

    // Определение координат новой точки в зависимости от направления движения и координат прошлой точки
    if (horizDir) {
        newPos.setX(curPos.x() + step);
    }
    else {
        newPos.setX(curPos.x() - step);
    }

    if (vertDir) {
        newPos.setY(curPos.y() + step);
    }
    else {
        newPos.setY(curPos.y() - step);
    }

    // Изменение направления движения в достижении границы окна
    QRect drawArea = this->rect();

    if (newPos.x() >= drawArea.right()) {
        newPos.setX(drawArea.right());
        horizDir = false;
    }
    if (newPos.x() <= drawArea.left()) {
        newPos.setX(drawArea.left());
        horizDir = true;
    }
    if (newPos.y() >= drawArea.bottom()) {
        newPos.setY(drawArea.bottom());
        vertDir = false;
    }
    if (newPos.y() <= drawArea.top()) {
        newPos.setY(drawArea.top());
        vertDir = true;
    }

    curPos = newPos;

    this->repaint();
}
