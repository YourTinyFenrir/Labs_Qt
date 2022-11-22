#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QPushButton"
#include "QFrame"
#include "QLabel"
#include "QLineEdit"
#include "QSpinBox"
#include "QSlider"
#include "QComboBox"
#include "QString"
#include "QLayout"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    // Создание различный Layout'ов
    QHBoxLayout* createHBoxLayout();
    QVBoxLayout* createVBoxLayout();
    QGridLayout* createGridLayout();

private slots:
    // Слоты для перевода числовых данных в строковые и наоборот
    void slot_setInt(QString);
    void slot_setStr(int);

    void slot_changeLayout(int); // Слот для смены Layout'a
    void slot_disable(); // Слот для блокировки/разблокировки объектов ввода/вывода

private:
    QFrame* fr; // Фрейм для размещения объектов ввода/вывода

    // Объекты ввода/вывода
    QLabel* label;
    QLineEdit* lEdit;
    QSpinBox* sBox;
    QSlider* slider;

    QComboBox* cBox; // Выбор Layout'ов
    QPushButton* exitButton; // Закрытие окна
    QPushButton* disableButton; // Блокировка/разблокировка
    QPushButton* fStyleButton; // Изменение стиля (в разработке)
};

#endif // WIDGET_H
