#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mydelegate.h"
#include "drawsimple.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создание и установка модели
    m_model = new MyModel();
    ui->tableView->setModel(m_model);
    ui->drawView->setModel(m_model);

    // Установка модели выбора
    QItemSelectionModel* m_selectionModel = ui->tableView->selectionModel();
    ui->drawView->setSelectionModel(m_selectionModel);

    // Создание и установка делегата
    MyDelegate* mg = new MyDelegate(ui->tableView);
    ui->tableView->setItemDelegate(mg);

    // Создание и установка заголовков
    QHeaderView* hv = ui->tableView->horizontalHeader();
    hv->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->drawView, SIGNAL(signal_addData(const MyRect&)), m_model, SLOT(slot_addData(const MyRect&)));

    m_model->test(); // Проверка модели
}

MainWindow::~MainWindow()
{
    delete m_model;
    delete ui;
}

