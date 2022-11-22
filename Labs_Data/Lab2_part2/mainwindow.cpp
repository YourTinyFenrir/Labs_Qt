#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QInputDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dbc = new DataBaseController();
}

MainWindow::~MainWindow()
{
    delete dbc;
    delete ui;
}

void MainWindow::on_action_createModels_triggered()
{
    // Создание моделей
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("type");
    model->select();

    QSqlRelationalTableModel* relModel = new QSqlRelationalTableModel();
    relModel->setTable("figure");
    relModel->select();

    // Установка отношения между моделями
    relModel->setRelation(1, QSqlRelation("type", "id", "type_name"));

    ui->tableView_main->setModel(relModel);

    // Создание и установка делегата
    QSqlRelationalDelegate* delegate = new QSqlRelationalDelegate(ui->tableView_main);
    ui->tableView_main->setItemDelegate(delegate);

    // Настраиваем внешний вид заголовков
    QHeaderView* hv = ui->tableView_main->horizontalHeader();
    hv->setSectionResizeMode(QHeaderView::Stretch);

    qDebug() << "Модели созданы";
}

void MainWindow::on_action_DoQuery_triggered()
{
    QSqlQueryModel* queryModel = new QSqlQueryModel();

    QString queryStr = QInputDialog::getText(nullptr, "Введите текст запроса:", "Запрос");

    queryModel->setQuery(queryStr, dbc->getDb());

    if (queryModel->lastError().isValid())
        qDebug () << queryModel->lastError ();
    else {
         ui->tableView_query->setModel(queryModel);

         // Настраиваем внешний вид заголовков
         QHeaderView* hv = ui->tableView_query->horizontalHeader();
         hv->setSectionResizeMode(QHeaderView::Stretch);

         qDebug() << "Запрос выполнен";
    }
}
