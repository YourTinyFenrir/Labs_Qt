#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QIntValidator"
#include "QMessageBox"
#include "QWheelEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Установка валидатора для lineEdit
    QValidator* valid = new QIntValidator(0, 99);
    ui->lineEdit->setValidator(valid);

    ui->lineEdit->textChanged("25"); // Подача сигнала для установки первоначального значения на всех объектах ввода/вывода
}

MainWindow::~MainWindow()
{
    delete valid;
    delete ui;
}

void MainWindow::slot_setInt(QString str)
{
    // Слот для перевода строкового значения в числовое от LineEdit
    ui->spinBox->setValue(str.toInt());
    ui->hSlider->setValue(str.toInt());
}

void MainWindow::slot_setStr(int num)
{
    // Слот для перевода числового значения в строковое от SpinBox/Slider
    ui->lineEdit->setText(QString::number(num));
}

void MainWindow::slot_showScale(int num)
{
    // Слот для отображения масштаба в статусбаре
    ui->statusbar->showMessage("Масштаб изображения: " + QString::number(num), 0);
}

void MainWindow::on_action_About_triggered()
{
    QMessageBox::about(this, "Справка", "Оч полезная информация, запоминай");
}

void MainWindow::wheelHasSpinned(bool dir)
{
    if (dir && ui->hSlider->value() < ui->hSlider->maximum()) // Если колесико было прокручено вперед и текущее значение меньше верхней границы
        ui->hSlider->valueChanged(ui->hSlider->value() + 1); // Увеличить значение на 1

    if (!dir && ui->hSlider->value() > ui->hSlider->minimum()) // Если колесико было прокручено назад и текущее значение больше нижней границы
        ui->hSlider->valueChanged(ui->hSlider->value() - 1);  // Уменьшить значение на 1
}

void MainWindow::wheelEvent(QWheelEvent* ev)
{
    wheelHasSpinned(ev->angleDelta().y() >= 0); // В параметр передаем знак результата вращения колесика (в какую сторону было произведено вращение)
}
