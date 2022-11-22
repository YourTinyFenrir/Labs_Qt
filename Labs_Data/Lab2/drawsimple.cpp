#include "drawsimple.h"
#include "QMouseEvent"
#include "QDebug"
#include "QSqlTableModel"

DrawSimple::DrawSimple(QWidget *parent) : QAbstractItemView(parent)
{
    m_isDrawing = false;
}

QRect DrawSimple::visualRect(const QModelIndex&) const
{
    return viewport()->rect();
}

void DrawSimple::scrollTo(const QModelIndex&, QAbstractItemView::ScrollHint)
{

}

QModelIndex DrawSimple::indexAt(const QPoint&) const
{
    return QModelIndex();
}

QModelIndex DrawSimple::moveCursor(QAbstractItemView::CursorAction, Qt::KeyboardModifiers)
{
    // Возвращаем индекс текущего элемента
    QModelIndex current = this->currentIndex();
    return current;
}

bool DrawSimple::isIndexHidden(const QModelIndex&) const
{
    return false;
}

QRegion DrawSimple::visualRegionForSelection(const QItemSelection&) const
{
    QRegion region;
    region = viewport()->rect();
    return region;
}

void DrawSimple::paintEvent(QPaintEvent*)
{
    QPainter painter(viewport());

    QSqlTableModel* model = static_cast<QSqlTableModel*>(this->model());

    if (model != nullptr) {

        // Рисуем поочередно каждый прямойгольник из модели
        for (int i = 0; i < model->rowCount(); ++i) {

            QModelIndex index = model->index(i, 1);
            QVariant var = model->data(index, Qt::DisplayRole);
            QColor penColor = var.value<QColor>();

            index = model->index(i, 2);
            var = model->data(index, Qt::EditRole);
            Qt::PenStyle penStyle = var.value<Qt::PenStyle>();

            index = model->index(i, 3);
            var = model->data(index, Qt::EditRole);
            qreal penWidth = var.value<qreal>();

            QPen pen(penColor);
            pen.setStyle(penStyle);
            pen.setWidth(penWidth);

            index = model->index(i, 4);
            var = model->data(index, Qt::EditRole);
            int left = var.value<int>();

            index = model->index(i, 5);
            var = model->data(index, Qt::EditRole);
            int top = var.value<int>();

            index = model->index(i, 6);
            var = model->data(index, Qt::EditRole);
            int width = var.value<int>();

            index = model->index(i, 7);
            var = model->data(index, Qt::EditRole);
            int height = var.value<int>();

            MyRect rect(pen, QRect(left, top, width, height));

            // Если проверяемый прямоугольник - текущий, то закрашиваем его
            if (i == currentIndex().row())
                rect.drawCurrentRect(painter);
            else
                rect.drawRect(painter);
        }

    }
}

void DrawSimple::currentChanged(const QModelIndex&, const QModelIndex&)
{
    viewport()->update ();//вызывается перерисовка области просмотра
}

void DrawSimple::mousePressEvent(QMouseEvent *event)
{
    // Если нажата правая кнопка мыши, то начинаем рисовать
    if (event->button() == Qt::RightButton) {

        // Фиксируем стартовую точку
        m_newRect.setRectLeft(event->localPos().x());
        m_newRect.setRectTop(event->localPos().y());
        m_newRect.setRectWidth(0);
        m_newRect.setRectHeight(0);

        m_isDrawing = true; // Устанавливаем признак, что начался процесс рисования
    }
    else
        QAbstractItemView::mousePressEvent(event);
}

void DrawSimple::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isDrawing) {
        m_newRect.setRectWidth(event->localPos().x() - m_newRect.rectLeft());
        m_newRect.setRectHeight(event->localPos().y() - m_newRect.rectTop());

        viewport()->update();

        m_isDrawing = false;

        emit(signal_addData(m_newRect)); // Сообщаем о добавлении прямоугольника

        setCurrentIndex(model()->index(model()->rowCount() - 1, 0)); // Выделяем нарисованный прямоугольник как текущий
    }
    else
        QAbstractItemView::mouseMoveEvent(event);
}

void DrawSimple::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDrawing) {
        m_newRect.setRectWidth(event->localPos().x() - m_newRect.rectLeft());
        m_newRect.setRectHeight(event->localPos().y() - m_newRect.rectTop());

        viewport()->update();
    }
    else
        QAbstractItemView::mouseReleaseEvent(event);
}
