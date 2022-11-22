#ifndef DRAWSIMPLE_H
#define DRAWSIMPLE_H

#include <QWidget>
#include <QAbstractItemView>
#include "myrect.h"
#include "QPainter"

class DrawSimple : public QAbstractItemView
{
    Q_OBJECT
public:
    explicit DrawSimple(QWidget *parent = nullptr);

signals:
    void signal_addData(MyRect); // Сигнал о добавлении данных

public:
    QRect visualRect(const QModelIndex &index) const;
    void scrollTo(const QModelIndex &index, ScrollHint hint);
    QModelIndex indexAt(const QPoint &point) const;

protected:
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
    int horizontalOffset() const { return 0; };
    int verticalOffset() const { return 0; };
    bool isIndexHidden(const QModelIndex &index) const;
    void setSelection(const QRect&, QItemSelectionModel::SelectionFlags) {};
    QRegion visualRegionForSelection(const QItemSelection &selection) const;
    void paintEvent(QPaintEvent *event);

protected slots:
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    MyRect m_newRect; // Рисуемый в данный момент прямоугольник
    bool m_isDrawing; // Идет ли процесс рисования в данный момент
    QPen pen; // Кисть для рисования
};

#endif // DRAWSIMPLE_H
