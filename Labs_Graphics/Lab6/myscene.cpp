#include "myscene.h"
#include "QGraphicsSceneMouseEvent"
#include "QGraphicsRectItem"
#include "QGraphicsEllipseItem"
#include "QPen"

MyScene::MyScene(QWidget *parent) : QGraphicsScene(parent)
{
    QGraphicsScene::setSceneRect(0, 0, 500, 500); // Фиксируем логические размеры
    this->data = new Data(Qt::blue, 2.0, Qt::SolidLine); // Устанавливаем первоначальные данные

    type = shapeType::RECTANGLE; // Устанавливаем первоначальный тип примитива
}

MyScene::~MyScene()
{
    delete data;
}

void MyScene::slot_chooseColor()
{
    QColor clr = QColorDialog::getColor(); // Вызов диалога

    // Проверка, выбрал ли пользователь цвет или закрыл диалоговое окно
    if (clr.isValid()) {
        data->color = clr;
    }
}

void MyScene::slot_settings()
{
    Dialog d(nullptr, data); // Создаем диалоговое окно

    // Если пользователь сохранил выбор (нажал "Ок")
    if (d.exec() == QDialog::Accepted) {
        data = d.getData(); // Получаем обновленные данные
    }
}

void MyScene::slot_changeType()
{
    // Изменяем значение на противоположное
    if (type == shapeType::ELLIPSE)
        type = shapeType::RECTANGLE;
    else
        type = shapeType::ELLIPSE;
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Если нажата правая кнопка мыши, то начинаем рисовать примитив
    if (event->button() == Qt::RightButton) {

        m_startPoint = event->scenePos(); // Фиксируем стартовую точку

        // Создаем объект в зависимости от переменной type (прямоугольник или эллипс)
        if (type == shapeType::RECTANGLE)
            m_current = new QGraphicsRectItem(m_startPoint.x(), m_startPoint.y(), 0, 0); // Начальные параметры прямоугольника (длина и ширина) - 0
        else
            m_current = new QGraphicsEllipseItem(m_startPoint.x(), m_startPoint.y(), 0, 0);

        // Устанавливаем перо с заданными параметрами
        QPen pen(data->color);
        pen.setStyle(data->penStyle);
        pen.setWidth(data->width);
        m_current->setPen(pen);

        // Устанавливаем флаги для выделения и перетаскивания примитива
        m_current->setFlags(QGraphicsItem::ItemIsSelectable);
        m_current->setFlags(QGraphicsItem::ItemIsMovable);

        this->addItem(m_current); // Добавляем примитив на сцену
        m_drawingInProcess = true; // Устанавливаем признак, что начался процесс рисования

    }
    QGraphicsScene::mousePressEvent(event); // Для получения базовой функциональности (выделение, перетаскивание)
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Если процесс рисования начат
    if (m_drawingInProcess) {

        QPointF currentPos = event->scenePos(); // Получаем текущую логическую координату курсора
        QRectF rectF(m_startPoint, currentPos); // Создаем прямоугольник по начальной и текущей точке

        this->rect = rectF;

        // Приводим к типу в зависимости от переменной type (прямоугольник или эллипс)
        if (type == shapeType::RECTANGLE)
            qgraphicsitem_cast<QGraphicsRectItem*>(m_current)->setRect(rect.normalized()); // Приводим указатель базового типа к производному, устанавливаем примитив
                                                                                           // Перед сохранением нормализуем прямоугольник
        else
            qgraphicsitem_cast<QGraphicsEllipseItem*>(m_current)->setRect(rect.normalized());
    }

    QGraphicsScene::mouseMoveEvent(event); // Для получения базовой функциональности (выделение, перетаскивание)
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    // Если процесс рисования начат
    if (m_drawingInProcess) {

        m_drawingInProcess = false; // Завершаем процесс рисования
        m_current = nullptr; // Обнуляем указатель на примитив

        signal_newShape(type, rect, data);

    }

    QGraphicsScene::mouseReleaseEvent(event); // Для получения базовой функциональности (выделение, перетаскивание)
}
