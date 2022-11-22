#include "widget.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QIntValidator"
#include "QFont"
#include "QStyleFactory"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //this->setStyle(QStyleFactory::create("fusion"));

    // Создание фрейма с объектами вода
    fr = new QFrame(this);
    fr->setObjectName("fr");
    fr->setFrameStyle(1);

    // Создание объектов ввода
    label = new QLabel(fr);
    lEdit = new QLineEdit(fr);
    sBox = new QSpinBox(fr);
    slider = new QSlider(Qt::Horizontal, fr);

    // Установка имен объектов
    label->setObjectName("label");
    lEdit->setObjectName("lEdit");
    sBox->setObjectName("sBox");
    slider->setObjectName("slider");

    // Настройка label'a
    label->setFrameStyle(1);
    label->setMinimumWidth(40);
    label->setMaximumHeight(25);
    label->setAlignment(Qt::AlignCenter);
    label->setDisabled(true); // Через lebel данные вводить нельзя

    // Добавление валидатора (для ограничения значений)
    QIntValidator* intValid = new QIntValidator(0, 50, lEdit);
    lEdit->setValidator(intValid);
    lEdit->setMinimumWidth(40);

    // Настройка SpinBox'a
    sBox->setMaximum(50);
    sBox->setFixedSize(sBox->sizeHint());

    // Настройка Slider'a
    slider->setRange(0, 50);
    slider->setTickPosition(QSlider::TicksBothSides); // Для отображения "рисочек"
    slider->setTickInterval(10);
    slider->setSingleStep(1);
    slider->setMinimumWidth(50);

    // Настройка ComboBox'a
    cBox = new QComboBox();
    cBox->setObjectName("cBox");
    cBox->addItem("Horizontal layout");
    cBox->addItem("Vertical layout");
    cBox->addItem("Grid layout");

    // Создание кнопок меню
    exitButton = new QPushButton("Закрыть");
    disableButton = new QPushButton("Disable");
    fStyleButton = new QPushButton("Fusion style");

    // Установка имен объектов
    exitButton->setObjectName("exitButton");
    disableButton->setObjectName("disableButton");
    fStyleButton->setObjectName("fStyleButton");

    // Создание Layout'ов
    QHBoxLayout* widgetLayout = new QHBoxLayout(this);
    QHBoxLayout* frameLayout = createHBoxLayout(); // Изначально устанавливается горизонтальный Layout
    QVBoxLayout* buttonsLayout = new QVBoxLayout();

    // Установка имен Layout'ов
    widgetLayout->setObjectName("widgetLayout");
    buttonsLayout->setObjectName("buttonsLayout");

    // Добавление объектов на layout окна
    widgetLayout->addWidget(fr);
    widgetLayout->addLayout(buttonsLayout);

    // Добавление виджетов на Layout фрейма
    frameLayout->addWidget(label);
    frameLayout->addWidget(lEdit);
    frameLayout->addWidget(sBox);
    frameLayout->addWidget(slider);

    // Добавление виджетов на layout для кнопок
    buttonsLayout->addWidget(cBox);
    buttonsLayout->addWidget(exitButton);
    buttonsLayout->addWidget(disableButton);
    buttonsLayout->addWidget(fStyleButton);

    //dumpObjectTree(); // ??? Вывод дерева объектов в консоль

    // Установка соединения для кнопок
    connect(cBox, SIGNAL(activated(int)), this, SLOT(slot_changeLayout(int)));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(disableButton, SIGNAL(clicked()), this, SLOT(slot_disable()));

    // установка соединения с label
    connect(lEdit, SIGNAL(textChanged(QString)), label, SLOT(setText(QString)));
    connect(sBox, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
    connect(slider, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));

    // Установка соединения с lineEdit
    connect(lEdit, SIGNAL(textChanged(QString)), this, SLOT(slot_setInt(QString)));
    connect(sBox, SIGNAL(valueChanged(int)), this, SLOT(slot_setStr(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(slot_setStr(int)));

    // Установка соединения между SpinBox и Slider
    connect(sBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), sBox, SLOT(setValue(int)));

    lEdit->textChanged("25"); // Подача сигнала для установки первоначального значения на всех объектах ввода/вывода
}

Widget::~Widget()
{
}

QHBoxLayout* Widget::createHBoxLayout()
{
    // Создание горизонтального layout
    QHBoxLayout* l = new QHBoxLayout(fr);

    l->setObjectName("frameLayout");
    l->addWidget(label);
    l->addWidget(lEdit);
    l->addWidget(sBox);
    l->addWidget(slider);

    return l;
}

QVBoxLayout* Widget::createVBoxLayout()
{
    // Создание вертикального layout
    QVBoxLayout* l = new QVBoxLayout(fr);

    l->setObjectName("frameLayout");
    l->addWidget(label);
    l->addWidget(lEdit);
    l->addWidget(sBox);
    l->addWidget(slider);

    return l;
}

QGridLayout* Widget::createGridLayout()
{
    // Создание табличного layout
    QGridLayout* l = new QGridLayout(fr);

    l->setObjectName("frameLayout");
    l->addWidget(label, 0, 0);
    l->addWidget(lEdit, 0, 1);
    l->addWidget(sBox, 1, 0);
    l->addWidget(slider, 1, 1);

    return l;
}

void Widget::slot_setInt(QString str)
{
    // Слот для перевода строкового значения в числовое от LineEdit
    sBox->setValue(str.toInt());
    slider->setValue(str.toInt());
}

void Widget::slot_setStr(int num)
{
    // Слот для перевода числового значения в строковое от SpinBox/Slider
    lEdit->setText(QString::number(num));
}

void Widget::slot_changeLayout(int num)
{
    // Слот для смены layout
    delete fr->layout(); // Очистить предыдущий layout фрейма

    switch(num){
    case 0:
        createHBoxLayout();
        break;
    case 1:
        createVBoxLayout();
        break;
    case 2:
        createGridLayout();
        break;
    default:
        break;
    }
}

void Widget::slot_disable()
{
    // Слот для блокировки/разблокировки объектов ввода/вывода
    if (lEdit->isEnabled()) {
        lEdit->setEnabled(false);
        sBox->setEnabled(false);
        slider->setEnabled(false);
        disableButton->setText("Enable");
    }
    else {
        lEdit->setEnabled(true);
        sBox->setEnabled(true);
        slider->setEnabled(true);
        disableButton->setText("Disable");
    }
}

