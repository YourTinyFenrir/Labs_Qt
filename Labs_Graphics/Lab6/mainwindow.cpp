#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "QTableWidgetItem"

#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pb_ellipse->setEnabled(false); // Делаем недоступной кнопку эллипса (изначально выбран прямоугольник, поэтому его кнопка активна)

    // Установка начальных параметров для трансформирования примитивов
    pastAngle = 0;
    pastScaleX = 1;
    pastScaleY = 1;
    pastShearX = 0;
    pastShearY = 0;

    // Создаем и устанавливаем собственную сцену
    ms = new MyScene();

    ui->gv_left->setScene(ms);
    ui->gv_right->setScene(ms);

    // Растягиваем столбцы на всю ширину таблицы
    QHeaderView* pheader = ui->tableWidget->horizontalHeader();  // Получаем указатель на представление горизонтальных заголовков
    pheader->setSectionResizeMode(QHeaderView::Stretch); // Устанавливаем режим растяжения - в качестве параметра - QHeaderView::Stretch

    // Соединяем кнопки меню с соответствующими слотами
    connect(ui->action_chooseColor, SIGNAL(triggered()), ms, SLOT(slot_chooseColor()));
    connect(ui->action_settings, SIGNAL(triggered()), ms, SLOT(slot_settings()));

    // Меняем тип фигуры, которую будем рисовать (данные)
    connect(ui->pb_ellipse, SIGNAL(clicked()), ms, SLOT(slot_changeType()));
    connect(ui->pb_rectangle, SIGNAL(clicked()), ms, SLOT(slot_changeType()));

    // Оповещаем о создании нового примитива на сцене
    connect(ms, SIGNAL(signal_newShape(MyScene::shapeType, QRectF, Data*)), this, SLOT(slot_addItem(MyScene::shapeType, QRectF, Data*)));

    connect(ui->sb_angle, SIGNAL(valueChanged(int)), this, SLOT(slot_rotate(int)));
    connect(ui->sb_scaleX, SIGNAL(valueChanged(double)), this, SLOT(slot_scaleX(double)));
    connect(ui->sb_scaleY, SIGNAL(valueChanged(double)), this, SLOT(slot_scaleY(double)));
    connect(ui->sb_shearX, SIGNAL(valueChanged(double)), this, SLOT(slot_shearX(double)));
    connect(ui->sb_shearY, SIGNAL(valueChanged(double)), this, SLOT(slot_shearY(double)));
}

MainWindow::~MainWindow()
{
    delete ms;
    delete ui;
}


void MainWindow::on_pb_ellipse_clicked()
{
    // Меняем тип фигуры, которую будем рисовать (интерфейс)
    ui->pb_ellipse->setEnabled(false);
    ui->pb_rectangle->setEnabled(true);
}

void MainWindow::on_pb_rectangle_clicked()
{
    // Меняем тип фигуры, которую будем рисовать (интерфейс)
    ui->pb_ellipse->setEnabled(true);
    ui->pb_rectangle->setEnabled(false);
}

void MainWindow::slot_addItem(MyScene::shapeType shapeType, QRectF rect, Data* data)
{
    int rc = ui->tableWidget->rowCount(); // Количество строк таблицы (порядковый номер добавленной строки, так как отсчет начинается с 0)

    ui->tableWidget->insertRow(rc); // Добавляем строку в таблицу

    // Тип примитива
    QTableWidgetItem* type = new QTableWidgetItem;
    if (shapeType == MyScene::shapeType::ELLIPSE) {
        type->setIcon(QIcon(":/icons/IconEllipse.ico"));
        type->setText("Ellipse");
    }
    else {
        type->setIcon(QIcon(":/icons/IconRect.ico"));
        type->setText("Rectangle");
    }

    // Параметры примитива
    QString str("(" + QString::number(rect.topLeft().x()) + "; " + QString::number(rect.topLeft().y()) + ") (" +
                QString::number(rect.bottomRight().x()) + "; " + QString::number(rect.bottomRight().y()) + ")");
    QTableWidgetItem* rct = new QTableWidgetItem(str);

    // Стиль пера
    QTableWidgetItem* penStyle = new QTableWidgetItem(data->penStyle);

    switch (data->penStyle) {

    case Qt::SolidLine:
        penStyle->setText("SolidLine");
        break;
    case Qt::DashDotLine:
        penStyle->setText("DashDotLine");
        break;
    case Qt::DashLine:
        penStyle->setText("DashLine");
        break;
    case Qt::DashDotDotLine:
        penStyle->setText("DashDotDotLine");
        break;
    case Qt::DotLine:
        penStyle->setText("DotLine");
        break;
    case Qt::CustomDashLine:
        penStyle->setText("CustomDashLine");
        break;

    }

    // Толщина пера
    QTableWidgetItem* width = new QTableWidgetItem(QString::number(data->width));

    // Цвет пера
    QString temp(QString::number(data->color.red()) + " " + QString::number(data->color.green()) + " " + QString::number(data->color.blue()));
    QTableWidgetItem* color = new QTableWidgetItem(temp);

    // Добавление item в строку таблицы
    ui->tableWidget->setItem(rc, 0, type);
    ui->tableWidget->setItem(rc, 1, rct);
    ui->tableWidget->setItem(rc, 2, penStyle);
    ui->tableWidget->setItem(rc, 3, width);
    ui->tableWidget->setItem(rc, 4, color);

}

void MainWindow::slot_rotate(int value)
{
    ui->gv_left->rotate(-pastAngle); // Возвращаем в исходное положение
    ui->gv_left->rotate(value); // Поворачиваем на заданную величину

    pastAngle = value; // Сохраняем последнее введенное значение
}

void MainWindow::slot_scaleX(double d)
{
    if (d > 0) { // Масштаб должен быть > 0
        ui->gv_left->scale(1/pastScaleX, 1/pastScaleY); // Возвращаем в исходный масштаб
        ui->gv_left->scale(ui->sb_scaleX->value(), ui->sb_scaleY->value()); // Изменяем масштаб

        pastScaleX = ui->sb_scaleX->value(); // Сохраняем последнее введенное значение
    }
}

void MainWindow::slot_scaleY(double d)
{
    if (d > 0) { // Масштаб должен быть > 0
        ui->gv_left->scale(1/pastScaleX, 1/pastScaleY); // Возвращаем в исходный масштаб
        ui->gv_left->scale(ui->sb_scaleX->value(), ui->sb_scaleY->value()); // Изменяем масштаб

        pastScaleY = ui->sb_scaleY->value(); // Сохраняем последнее введенное значение
    }
}

void MainWindow::slot_shearX(double d)
{
    ui->gv_left->shear(-pastShearX, -pastShearY); // Возвращаем в исходное положение
    ui->gv_left->shear(ui->sb_shearX->value(), ui->sb_shearY->value()); // Изменяем скос

    pastShearX = ui->sb_shearX->value(); // Сохраняем последнее введенное значение
}

void MainWindow::slot_shearY(double d)
{
    ui->gv_left->shear(-pastShearX, -pastShearY); // Возвращаем в исходное положение
    ui->gv_left->shear(ui->sb_shearX->value(), ui->sb_shearY->value()); // Изменяем скос

    pastShearY = ui->sb_shearY->value(); // Сохраняем последнее введенное значение
}
