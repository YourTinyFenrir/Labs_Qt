#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"
#include "QFile"
#include "QDebug"
#include "QMessageBox"
#include "QTime"
#include "QBuffer"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    memory = new QSharedMemory("SM");
}

MainWindow::~MainWindow()
{
    delete memory;
    delete ui;
}


void MainWindow::on_pb_send_clicked()
{
    // Отправка данных родительскому процессу

    QString str(ui->le_msgTo->text());
    QByteArray qbar = str.toUtf8();

    std::cout << qbar.data();
    std::cout.flush();

    QMessageBox::information(this, "Оповещение", "Данные отправлены");
}

void MainWindow::on_pb_receive_clicked()
{
    // Прием данных от родительского процесса

    QFile file;

    if (file.open(stdin, QIODevice::ReadOnly | QIODevice::Unbuffered))
    {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_14);

        QString str;
        QTime time;
        in >> str >> time;

        ui->le_msgFrom->setText(str + " - " + time.toString());

        file.flush();
        file.close();

        QMessageBox::information(this, "Оповещение", "Данные считаны");
    }
    else
        qDebug() << "Ошибка при открытии файла стандартного ввода";

}

void MainWindow::on_pb_attach_clicked()
{
    // Подключение к разделяемому разделу данных

    if (memory->attach()) {
        ui->pb_attach->setEnabled(false);
        QMessageBox::information(this, "Оповещение", "Подключение произошло успешно");
    }
    else
        QMessageBox::warning(this, "Оповещение", "Подключение не удалось");
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
