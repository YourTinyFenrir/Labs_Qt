#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"
#include "QMessageBox"
#include "QTime"
#include "QBuffer"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    proc = new QProcess();
    memory = new QSharedMemory("SM");

    ui->pb_kill->setEnabled(false);

    ui->pb_readShared->setEnabled(false);
    ui->pb_writeShared->setEnabled(false);

    connect(proc, SIGNAL(started()), this, SLOT(afterStart()));
    connect(proc, SIGNAL(errorOccurred(QProcess::ProcessError)), this, SLOT(afterError(QProcess::ProcessError)));
    connect(proc, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(afterFinish(int, QProcess::ExitStatus)));

    connect(proc, SIGNAL(readyReadStandardOutput()), this, SLOT(readFromChild()));
}

MainWindow::~MainWindow()
{
    delete proc;
    delete memory;
    delete ui;
}

void MainWindow::on_pb_start_clicked()
{
    // Запуск дочернего процесса с возможностью последующего взаимодействия

    QStringList strList = ui->le_params->text().split(';'); // Разделяем параметры запуска символом ';'
    proc->start(ui->le_name->text(), strList);
}

void MainWindow::on_pb_kill_clicked()
{
    // Принудительное завершение процесса
    proc->kill();
}

void MainWindow::on_pb_startDetached_clicked()
{
    // Запуск обособленного дочернего процесса (без параметров)

    QProcess* pr = new QProcess();
    qint64* pid = new qint64();

    pr->startDetached(ui->le_name->text(),  QStringList(), QString(), pid);

    qDebug() << "PID дочернего процесса - " << *pid;

    delete pid;
    delete pr;
}

void MainWindow::on_pb_startDetachedParams_clicked()
{
    // Запуск обособленного дочернего процесса (с параметрами)

    QProcess* pr = new QProcess();
    qint64* pid = new qint64();
    QStringList strList = ui->le_params->text().split(';'); // Разделяем параметры запуска символом ';'

    pr->startDetached(ui->le_name->text(),  strList, QString(), pid);

    qDebug() << "PID дочернего процесса - " << *pid;

    delete pr;
}

void MainWindow::on_pb_execute_clicked()
{
    // Запуск дочернего процесса и ожидание его завершения (без параметров)

    QProcess* pr = new QProcess();
    pr->execute(ui->le_name->text());
    delete pr;
}

void MainWindow::on_pb_executeParams_clicked()
{
    // Запуск дочернего процесса и ожидание его завершения (с параметрами)

    QProcess* pr = new QProcess();
    QStringList strList = ui->le_params->text().split(';'); // Разделяем параметры запуска символом ';'

    pr->execute(ui->le_name->text(), strList);

    delete pr;
}

void MainWindow::on_pb_toChild_clicked()
{
    // Отправка сообщения дочернему процессу

    QByteArray buff;
    QDataStream out(&buff, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_14);

    QString str = ui->le_toChild->text();
    QTime time;
    time = time.currentTime();

    out << str << time;

    if (out.status() != QDataStream::Ok)
        QMessageBox::critical(this, "Ошибка", "Ошибка записи");
    else {
        proc->write(buff);
        QMessageBox::information(this, "Оповещение", "Данные отправлены");
    }
}

void MainWindow::afterStart()
{
    // Обработка сигнала о старте дочернего процесса

    ui->pb_start->setEnabled(false);
    ui->pb_kill->setEnabled(true);
}

void MainWindow::afterError(QProcess::ProcessError err)
{
    // Обработка сигнала об ошибке

    QMessageBox::critical(this, "Ошибка", "Код ошибки: " + QString::number(err), QMessageBox::Ok);
}

void MainWindow::afterFinish(int exitCode, QProcess::ExitStatus exitStatus)
{
    // Обработка сигнала о завершении дочернего процесса

    ui->le_exitCode->setText(QString::number(exitCode));
    ui->le_exitStatus->setText(QString::number(exitStatus));

    ui->pb_start->setEnabled(true);
    ui->pb_kill->setEnabled(false);
}

void MainWindow::readFromChild()
{
    // Обработка сигнала о полкчении данных от дочернего процееса

    QByteArray data = proc->readAllStandardOutput();
    ui->le_fromChild->setText(QString(data));

    QMessageBox::information(this, "Оповещение", "Данные считаны");
}

void MainWindow::on_pb_createShared_clicked()
{
    // Создание разделяемого раздела памяти

    memory->create(128);

    ui->pb_createShared->setEnabled(false);
    ui->pb_readShared->setEnabled(true);
    ui->pb_writeShared->setEnabled(true);

    QMessageBox::information(this, "Оповещение", "Создан сегмент разделяемой памяти");
}

void MainWindow::on_pb_writeShared_clicked()
{
    // Запись данных в разделяемый раздел памяти

    if (memory->isAttached()) {
        QBuffer buffer;
        buffer.open(QBuffer::WriteOnly);

        QDataStream stream(&buffer);
        stream.setVersion(QDataStream::Qt_5_14);

        stream << ui->le_writeShared->text();
        int size = buffer.size();

        memory->lock();

        QByteArray bar = buffer.data();
        char* source = bar.data();
        char* dest = static_cast<char*>(memory->data());
        memcpy(dest, source, size);

        memory->unlock();
        buffer.close();

        QMessageBox::information(this, "Оповещение", "Данные записаны");
    }
    else
        QMessageBox::warning(this, "Оповещение", "Нет подключения к разделяемой памяти");
}

void MainWindow::on_pb_readShared_clicked()
{
    // Чтение данных из разделяемого раздела памяти

    if (memory->isAttached()) {
        QBuffer buffer;
        QDataStream stream(&buffer);
        stream.setVersion(QDataStream::Qt_5_14);

        memory->lock();
        int size = memory->size();
        char* mem = static_cast<char*>(memory->data());
        QByteArray bar(mem, size);

        buffer.setData(bar);
        buffer.open(QBuffer::ReadOnly);

        QString str;
        stream >> str;
        ui->le_readShared->setText(str);

        memory->unlock();
        buffer.close();

        QMessageBox::information(this, "Оповещение", "Данные считаны");
    }
    else
        QMessageBox::warning(this, "Оповещение", "Нет подключения к разделяемой памяти");
}
