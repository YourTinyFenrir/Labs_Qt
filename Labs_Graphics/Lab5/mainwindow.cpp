#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->glass->glassInit(); // Инициализируем "стакан"

    connect(ui->action_newGame, SIGNAL(triggered()), ui->glass, SLOT(slot_newGame())); // Пункт меню о начале игры
    connect(ui->pb_newGame, SIGNAL(clicked()), ui->glass, SLOT(slot_newGame())); // Кнопка начала игры
    connect(ui->glass, SIGNAL(signal_changeFigure(Figure*)), ui->nextFigure, SLOT(slot_setFigure(Figure*))); // Смена фигуры
    connect(ui->glass, SIGNAL(signal_setScore(int)), ui->lcdNumber, SLOT(display(int))); // Изменение счета
    connect(ui->pb_exit, SIGNAL(clicked()), this, SLOT(close())); // Завершение программы
}

MainWindow::~MainWindow()
{
    delete ui;
}

