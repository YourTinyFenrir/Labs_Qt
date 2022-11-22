#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mydelegate.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    dbc = new DataBaseController();
    ui->setupUi(this);
    connect(ui->drawView, SIGNAL(signal_addData(MyRect)), this, SLOT(slot_getData(MyRect)));
}

MainWindow::~MainWindow()
{
    delete dbc;
    delete ui;
}

void MainWindow::on_action_initTableModel_triggered()
{
    model = new QSqlTableModel();

    model->setTable(dbc->table());
    model->select();

    // Устанавливаем заголовки столбцов
    model->setHeaderData(1, Qt::Horizontal, "Цвет пера", Qt::DisplayRole);
    model->setHeaderData(2, Qt::Horizontal, "Стиль пера", Qt::DisplayRole);
    model->setHeaderData(3, Qt::Horizontal, "Толщина пера", Qt::DisplayRole);
    model->setHeaderData(4, Qt::Horizontal, "Левая", Qt::DisplayRole);
    model->setHeaderData(5, Qt::Horizontal, "Верхняя", Qt::DisplayRole);
    model->setHeaderData(6, Qt::Horizontal, "Ширина", Qt::DisplayRole);
    model->setHeaderData(7, Qt::Horizontal, "Высота", Qt::DisplayRole);

    // Создание и установка делегата
    MyDelegate* mg = new MyDelegate(ui->tableView);
    ui->tableView->setItemDelegate(mg);

    ui->drawView->setModel(model);

    ui->tableView->setModel(model);

    // Настраиваем внешний вид заголовков
    QHeaderView* hv = ui->tableView->horizontalHeader();
    hv->setSectionResizeMode(QHeaderView::Stretch);

    qDebug() << "Таблица для модели установлена";
}

void MainWindow::on_action_selectTable_triggered()
{
    model->setTable(dbc->table());
    model->select();
}

void MainWindow::on_action_insertRows_triggered()
{
    int count = model->rowCount();
    bool isOk = model->insertRows(count, 1);

    QModelIndex index = model->index(count, 0);
    model->setData(index, -1);

    if (!isOk)
        qDebug() << "Ошибка при добавлении строки";
}

void MainWindow::on_action_removeRows_triggered()
{
    int row = ui->tableView->currentIndex().row();
    bool isOk = model->removeRows(row, 1);

    if (!isOk)
        qDebug() << "Ошибка при удалении строки";
}

void MainWindow::slot_getData(MyRect rect)
{
    int count = model->rowCount();
    bool isOk = model->insertRows(count, 1);

    if (!isOk)
        qDebug() << "Ошибка при добавлении строки";
    else {
        QModelIndex index = model->index(count, 0);
        model->setData(index, count);

        index = model->index(count, 1);
        model->setData(index, rect.penColor());

        index = model->index(count, 2);
        model->setData(index, int(rect.penStyle()));

        index = model->index(count, 3);
        model->setData(index, rect.penWidth());

        index = model->index(count, 4);
        model->setData(index, rect.rectLeft());

        index = model->index(count, 5);
        model->setData(index, rect.rectTop());

        index = model->index(count, 6);
        model->setData(index, rect.rectWidth());

        index = model->index(count, 7);
        model->setData(index, rect.rectHeight());

        model->submitAll();
    }
}
