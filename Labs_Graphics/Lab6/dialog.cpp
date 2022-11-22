#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent,  Data* data) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Заполнение map стилями
    styles.insert(Qt::SolidLine, "SolidLine");
    styles.insert(Qt::DashDotLine, "DashDotLine");
    styles.insert(Qt::DashLine, "DashLine");
    styles.insert(Qt::DashDotDotLine, "DashDotDotLine");
    styles.insert(Qt::DotLine, "DotLine");
    styles.insert(Qt::CustomDashLine, "CustomDashLine");

    // Наполнение comboBox из map
    for (QString name : styles) {
        ui->cb_style->addItem(name);
    }

    ui->cb_style->setCurrentText(styles.value(data->penStyle)); // Установка текущего стиля в combobox
    ui->sb_width->setValue(data->width); // Установка толщины, полученной от главного окна

    // Получение компонент цвета и установка их в соответствующие элементы интерфейса
    int *r = new int(), *g = new int(), *b = new int();
    data->color.getRgb(r, g, b);

    ui->hs_red->setValue(*r);
    ui->hs_green->setValue(*g);
    ui->hs_blue->setValue(*b);

    // Очистка динамически созданных объектов
    delete r;
    delete g;
    delete b;

    // Соединяем элементы интерфейса и данные для их обновления
    connect(ui->cb_style, SIGNAL(activated(int)), this, SLOT(slot_updateData()));
    connect(ui->sb_width, SIGNAL(valueChanged(double)), this, SLOT(slot_updateData()));
    connect(ui->hs_red, SIGNAL(valueChanged(int)), this, SLOT(slot_updateData()));
    connect(ui->hs_green, SIGNAL(valueChanged(int)), this, SLOT(slot_updateData()));
    connect(ui->hs_blue, SIGNAL(valueChanged(int)), this, SLOT(slot_updateData()));

    // Соединяем диалоговое окно и виджет для отображения изменений параметров рисования
    connect(this, SIGNAL(signal_updateData(Data*)), ui->pattern, SLOT(slot_updatePen(Data*)));

    signal_updateData(data); // Подаем сигнал, чтобы на созданном виджете отобразились текущие данные
}

Dialog::~Dialog()
{
    delete ui;
}

Data* Dialog::getData()
{
    // Собираем данные из элементов интерфейса
    QColor clr(ui->hs_red->value(), ui->hs_green->value(), ui->hs_blue->value());
    qreal w = ui->sb_width->value();
    Qt::PenStyle ps = styles.key(ui->cb_style->currentText());

    return new Data(clr, w, ps);
}

void Dialog::slot_updateData()
{
    signal_updateData(getData());
}

