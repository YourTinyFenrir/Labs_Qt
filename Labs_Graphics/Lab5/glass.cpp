#include "glass.h"
#include "QPainter"
#include "QBrush"
#include "QKeyEvent"
#include "QMessageBox"
#include "QString"

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    gameOn = false;
    this->setFixedSize(cellSize * m_rows, cellSize * m_columns);

    idTimer = -1;

    cur = new Figure(cellSize);
    next = new Figure(cellSize);
}

Glass::~Glass()
{
    if (idTimer != -1) { // Если уже был создан таймер, удаляем его
        killTimer(idTimer);
    }

    delete cur;
    delete next;
}

void Glass::glassInit()
{
    field.resize(m_rows);

    for (int i = 0; i < m_rows; ++i)
        field[i].resize(m_columns);

    glassClear();
}

void Glass::glassClear()
{
    for (int i = 0; i < m_rows; ++i)
        field[i].fill(emptyCell); // Задаем всем клеткам поля цвет "пустой клетки"

    timerInterval = 600;
    score = 0; // Обнуление счета
}

void Glass::figureClear(QPoint pos)
{
    for (int i = 0; i < 3; ++i) // Для всех ячеек фигуры
        if (pos.x() - i >= 0) // Если они попадают на поле
            field[pos.x() - i][pos.y()] = emptyCell; // Заменить цвет на "пустой"
}

void Glass::changeFigure()
{
    *cur = *next; // Заменяем текущую фигуру на следующую через оператор присваивания
    cur->setCurrentPos(QPoint(0, m_columns / 2)); // Меняем позицию на начальную
    next->makeRandomColors(); // Следующей фигуре задаем новые цвета
    next->setCurrentPos(QPoint(-1, -1)); // Следующей фигуре задаем параметры -1, -1

    signal_changeFigure(next); // Вызов сигнала для обновления виджета со следующей фигурой
}

void Glass::checkResult()
{
    bool res = false; // Найдена ли комбинация
    QColor curClr(0, 0, 0); // Проверяемый цвет
    int startIndex = 0; // Индекс ячейки, а которой началась комбинация
    int count = 0; // Счетчик ячеек в комбинации

    for (int i = m_rows - 1; i >= 0 && !res; --i) {

        if (count > 2) { // Если комбинация добралась на последней ячейке прошлой строки, то фиксируем результат
            removeCombination(startIndex, m_columns - 1, i); // Берем последнюю ячейку строки (с поправкой, что в массиве отсчет начинается с 0)

            // Обновляем счет и вызываем сигнал, чтоб данные отобразились на LCDNumber
            score += count * 10;
            signal_setScore(score);

            res = true;
        }
        else { // Иначе обнуляем данные
            curClr.setRgb(0, 0, 0);
            startIndex = 0;
            count = 0;
        }

        for (int j = 0; j < m_columns && !res; ++j) {
            if (field[i][j] == curClr && field[i][j] != emptyCell) { // Если цвет ячейки совпадает с предыдущими в строке и не является пустой ячейкой
                count++;
            }
            else if (count > 2) { // Если счетчик больше 3, то удалить ячейки, пополнить значение счета
                removeCombination(startIndex, j-1, i); // Текущая ячейка не входит в комбинацию, поэтому j-1

                // Обновляем счет и вызываем сигнал, чтоб данные отобразились на LCDNumber
                score += count * 10;
                signal_setScore(score);

                res = true;
            }
            else { // Комбинация не набрана, обнуляем данные
                curClr = field[i][j];
                startIndex = j;
                count = 1;
            }
        }
    }

    if (res)
        checkResult();
}

void Glass::removeCombination(int first, int second, int row)
{
    // Начиная со строки, где была найдена комбинация,
    // смещаем вышестоящие строки вниз,
    // самую верхнюю строку поля заполняем пустыми ячейками
    for (int i = row; i >= 0; --i)
        for (int j = first; j <= second; ++j)
            if (i != 0)
                field[i][j] = field[i-1][j];
            else
                field[i][j] = emptyCell;
}

void Glass::slot_newGame()
{
    gameOn = true;

    glassClear(); // Очистка поля

    // Создание новых фигур
    cur->makeRandomColors();
    cur->setCurrentPos(QPoint(0, m_columns / 2)); // Нижний элемент фигуры на верх поля и
                                                  // По горизонтали - по середине
    next->makeRandomColors();
    next->setCurrentPos(QPoint(-1, -1)); // Следующей фигуре задаем параметры -1, -1

    this->setFocus(); // Для возможности управления клавиатурой
    this->repaint();

    if (idTimer != -1) { // Если уже был создан таймер, удаляем его
        killTimer(idTimer);
    }
    idTimer = startTimer(timerInterval); // Запускаем таймер

    signal_changeFigure(next); // Вызов сигнала для обновления виджета со следующей фигурой
}

void Glass::paintEvent(QPaintEvent* ev)
{
    Q_UNUSED(ev);

    QPainter painter(this);

    // Отрисовка падающей фигуры
    if (gameOn) {

        QPoint curPos = cur->getCurrentPos();

        // Если часть фигуры помещается на поле - отрисовываем ее
        for (int i = 0; i < 3; ++i)
            if (curPos.x() - i >= 0) // -i, потому что curPos - нижняя точка фигуры
                field[curPos.x() - i][curPos.y()] = cur->getArr(i);
    }

    // Отрисовка поля
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            QBrush br(field[i][j]);
            QPoint leftUp(j * cellSize + 1,  // Номер столбца изменяет координату по X
                          i * cellSize + 1); // Номер строки - по Y
            painter.fillRect(leftUp.x(), leftUp.y(), cellSize - 1, cellSize - 1, br); // Добавляем/убираем единицу для отображения сетки
        }
    }
}

void Glass::keyPressEvent(QKeyEvent* ev)
{
    if (gameOn) // Если идет игра
    {
        QPoint curPoint = cur->getCurrentPos(); // Текущая позиция фигуры

        switch(ev->key()) { // Код нажатой клавиши

        // Перемещаем фигуру влево/вправо
        case Qt::Key_Left:
            if (cur->getCurrentPos().y() > 0) {
                figureClear(curPoint); // Очищаем часть поля, где до перемещения находилась фигура
                cur->setCurrentPos(QPoint(curPoint.x(), curPoint.y() - 1)); // Смещаем текущую позицию фигуры
            }
        break;
        case Qt::Key_Right:
            if (cur->getCurrentPos().y() < m_columns - 1) {
                figureClear(curPoint);
                cur->setCurrentPos(QPoint(curPoint.x(), curPoint.y() + 1));
            }
        break;

        // Меняем цвета в фигуре
        case Qt::Key_Down:
            cur->rotateColors(false);
        break;
        case Qt::Key_Up:
            cur->rotateColors(true);
        break;

        // Сразу опускаем фигуру
        case Qt::Key_Space:
            figureClear(cur->getCurrentPos());
            while (cur->getCurrentPos().x() != m_rows - 1 // Пока непоследняя строка
                   && field[cur->getCurrentPos().x() + 1][cur->getCurrentPos().y()] == emptyCell) { // и нижерасположенная клетка - пустая
                // Перемещаем фигуру вниз
                QPoint temp = cur->getCurrentPos();
                temp.setX(temp.x() + 1);
                cur->setCurrentPos(temp);
            }
            this->repaint();
        break;

        default:
            QWidget::keyPressEvent(ev); // При нажатии любых других клавиш вызываем базовую обработку события
        }
    }
    else
        QWidget::keyPressEvent(ev); // Предоставляем возможность базовому
                                    // классу обработать событие
}

void Glass::timerEvent(QTimerEvent*)
{
    QPoint cp = cur->getCurrentPos();

    if (cp.x() == m_rows - 1) { // Если достигли нижней границы поля
        changeFigure(); // Замена фигуры
        checkResult(); // Проверка, есть ли комбинации, которые можно удалить
    }
    else if (field[cp.x() + 1][cp.y()] == emptyCell) { // Если клетка, расположенная ниже, свободна
        // Увеличиваем номер строки на 1
        cp.setX(cp.x() + 1);
        cur->setCurrentPos(cp);

        if (cp.x() - 3 >= 0) // Если клетка выше фигуры расположена на поле
            field[cp.x() - 3][cp.y()] = emptyCell; // Делаем ее пустой (иначе фигура будет "растягиваться" от начала до конца поля)
    }
    else if (field[0][m_columns / 2] != emptyCell) { // Если стартовая клетка занята
        gameOn = false; // Игра завершается
        killTimer(idTimer); // Удаляем таймер
        idTimer = -1; // Изменяем idTimer на значение, когда таймер не создан
        QMessageBox::warning(this, "Игра окончена", "Итоговый счет: " + QString::number(score));
    }
    else {
        changeFigure();
        checkResult();
    }

    this->repaint();
}
