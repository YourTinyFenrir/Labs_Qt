#ifndef GLASS_H
#define GLASS_H

#include <QWidget>
#include <QVector>
#include <QColor>
#include "figure.h"

class Glass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(unsigned int rows READ rows WRITE setRows)
    Q_PROPERTY(unsigned int columns READ columns WRITE setColumns)

public:
    explicit Glass(QWidget *parent = nullptr);
    ~Glass();

    unsigned int rows() const
    {
        return m_rows;
    }

    unsigned int columns() const
    {
        return m_columns;
    }

    void glassInit(); // Формирование игрового поля исходя из имеющихся размеров
    void glassClear(); // Очистка игрового поля
    void figureClear(QPoint); // Очистка фигуры (при смещении в сторону)
    void checkResult(); // Проверка, сформировались ли комбинации ячеек
    void removeCombination(int, int, int); // Удаление найденной комбинации
    void changeFigure();

signals:
    void signal_changeFigure(Figure*); // Смена фигур
    void signal_setScore(int); // Для отображения счета

public slots:
    void setRows(unsigned int rows)
    {
        m_rows = rows;
    }

    void setColumns(unsigned int columns)
    {
        m_columns = columns;
    }

    void slot_newGame(); // Слот для начала новой игры

private:
    const uint cellSize = 40; // Размер клетки
    uint timerInterval; // Интервал обновления положения фигур
    const QColor emptyCell = Qt::gray; // Цвет пустой клетки

    // Размеры игровой области (в клетках)
    int m_rows;
    int m_columns;

    QVector<QVector<QColor>> field; // Игровое поле

    bool gameOn; // Идет ли игра?
    int score; // Счетчик очков

    Figure* cur; // Фигура, находящаяся на поле в данный момент
    Figure* next; // Фигура, которая появится следующей

    int idTimer; // Идентификатор таймера

protected:
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent*);
    void timerEvent(QTimerEvent*);
};

#endif // GLASS_H
