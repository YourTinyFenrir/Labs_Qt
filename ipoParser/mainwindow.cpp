#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"
#include "QFileDialog"
#include "QFile"
#include "QTextStream"
#include "QStringList"
#include "QDir"
#include "QRegExp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->filePath->setText("Выберите файл формата .ipo");
    ui->folderPath->setText("Выберите папку с файлами формата .ip");

    ui->progressBar->reset();
    progressCount = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile(QString path)
{
    sourceFile.clear(); // Очищаем вектор от данных предыдущего файла

    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "File open error";
    else {

        QTextStream in(&file);
        in.setCodec("IBM 866"); // Устанавливаем кодировку

        // Считываем файл построчно, пока не конец файла
        while (!in.atEnd()) {
            QString str;
            in >> str;
            sourceFile.push_back(str); // Добавляем строку в вектор
        }

    }
}

void MainWindow::on_pb_file_clicked()
{
    QString str = QFileDialog::getOpenFileName();
    ui->filePath->setText(str);
}

void MainWindow::on_pb_folder_clicked()
{
    QString str = QFileDialog::getExistingDirectory();
    ui->folderPath->setText(str);
}

void MainWindow::on_pb_start_clicked()
{
    // Обновляем элементы интерфейса
    ui->progressBar->reset();
    progressCount = 0;
    ui->listWidget->clear();

    // Очищаем контейнеры с данными
    sourceFile.clear();
    hashTable.clear();

    // Читаем исходный файл
    readFile(ui->filePath->text());

    // Перебираем построчно прочитанный файл, отбираем необходимые данные
    for (QString str : sourceFile) {

        QStringList list = str.split(':'); // Разбиваем строку по ':'

        if (list.size() == 6) // Если строка разделилась на 6 частей (начальные строки отсеются), добавляем ее необходимые части в хэш-таблицу
            hashTable.insert(list[5], list[2]); // Пример проверяемых строк - 11.04.20:0083:57210:57210:0:145a24
                                                // list[5] - идентификатор, list[2] - контрольная сумма

        // Обновляем progressBar
        progressCount += 50.0 / double(sourceFile.size());
        this->ui->progressBar->setValue(progressCount);
    }

    // Получаем список файлов, расположенных в указанной папке
    QDir dir(ui->folderPath->text());
    dir.setFilter(QDir::Files);
    QStringList lst = dir.entryList();

    // Перебираем файлы
    for (QString fName : lst) {

        readFile(dir.path() + "/" + fName); // Указываем полный путь до файла

        // Оставляем от названия файла только номер
        fName.remove(0, 2); // Убираем начало вида "А*"
        fName.remove(3, 3); // Убираем окончание .ip
        fName.remove(QRegExp("^[0]*")); // Убираем нули в начале

        QString mask = "145p" + fName; // Добавляем начало из файла .ipo (автоматизировать или дать возможность задавать вручную)

        // Поиск по названию файла в хэш-таблице
        auto findResult = hashTable.find(mask);
        QString strToOutput = "";

        if (findResult != hashTable.end()) { // Если поиск прошел успешно

            strToOutput += findResult.key() + " - " + findResult.value();

            // Сравнение контрольных сумм
            if (findResult.value() != sourceFile.at(3)) // sourceFile.at(3) - контрольная сумма в ip-файле
                strToOutput += " (Error)";
        }
        else
            strToOutput += mask + " - not found";

        // Обновление интерфейса
        this->ui->listWidget->addItem(strToOutput);
        progressCount += 50.0 / double(lst.size());
        this->ui->progressBar->setValue(progressCount);

    }

    this->ui->progressBar->setValue(100); // ахаххаххахха)))))

}
