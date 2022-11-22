#include "databasecontroller.h"
#include <QInputDialog>

void DataBaseController::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    if (db.isValid()) {

        db.setDatabaseName("Test");

        if (db.open())
            qDebug() << "Соединение установлено";
        else
            qDebug() << db.lastError();
    }
    else
        qDebug() << db.lastError();
}

void DataBaseController::closeConnection()
{
    if (db.isValid()) {
        db.close();
        qDebug() << "Соединение закрыто";
    }
    else
        qDebug() << db.lastError();
}

void DataBaseController::createTable()
{
    if (db.isValid()) {

        QString queryStr = "CREATE TABLE rectangle ( "
                           "id INTEGER  PRIMARY KEY, "
                           "penColor  VARCHAR, "
                           "penStyle  INTEGER, "
                           "penWidth INTEGER, "
                           "rectLeft INTEGER, "
                           "rectTop INTEGER, "
                           "rectWidth INTEGER, "
                           "rectHeight INTEGER) ";

        QSqlQuery query;
        if (query.exec(queryStr))
            qDebug() << "Таблица создана";
        else
            qDebug() << query.lastError();
    }
    else
        qDebug() << db.lastError();
}

void DataBaseController::dropTable()
{
    if (db.isValid()) {

        QSqlQuery query;

        if (db.tables().contains(tableName)) {

            QString queryStr = "DROP TABLE " + tableName;

            if (query.exec(queryStr))
                qDebug() << "Таблица удалена";
            else
                qDebug() << query.lastError();

        }
        else
            qDebug() << query.lastError();

    }
    else
        qDebug() << db.lastError();
}

void DataBaseController::insertInto()
{
    // Добавим один прямоугольник просто через запрос
    QString queryStr=
    "INSERT INTO rectangle (id, penColor, penStyle)"
    "VALUES (0, '#ff0000', 1)";

    QSqlQuery query;

    bool res = query.exec(queryStr);

    if (!res)
        qDebug() << query.lastError();

    // Вставка значений по имени поля (в стиле Oracle)
    queryStr =
    "INSERT INTO rectangle (rectLeft, rectTop, rectWidth, rectHeight)"
    "VALUES (:rectLeft, :rectTop, :rectWidth, :rectHeight)";

    query.prepare(queryStr);

    query.bindValue(":rectLeft", 100);
    query.bindValue(":rectTop", 20);
    query.bindValue(":rectWidth", 60);
    query.bindValue(":rectHeight", 60);

    res = query.exec();

    if (!res)
        qDebug() << query.lastError();

    // Вставка значений по позиции поля (в стиле ODBC)
    queryStr = // Количество ? должно ТОЧНО совпадать с числом полей, перечисленных в INSERT INTO
    "INSERT INTO rectangle (penColor, penStyle, penWidth, rectLeft)"
    "VALUES (?,?,?,?)";

    query.prepare(queryStr);

    QVector<MyRect> rectVec = { MyRect(QPen(QColor("#00ff00"), 2, Qt::SolidLine), QRect(10, 10, 10, 10)),
                                MyRect(QPen(QColor("#0000ff"), 1, Qt::DashLine), QRect(0, 0, 200, 100)) };

    for (auto &val : rectVec)
    {
         query.addBindValue(val.penColor());
         query.addBindValue(static_cast<uint>(val.penStyle()));
         query.addBindValue(val.penWidth());
         query.addBindValue(val.rectLeft());
         query.addBindValue(val.rectTop());
         query.addBindValue(val.rectWidth());
         query.addBindValue(val.rectHeight());

         res = query.exec();

         if (!res)
             qDebug() << query.lastError();

    }

    qDebug() << "Данные добалены";

}

void DataBaseController::printTable()
{
    if (db.isValid()) {

        QSqlQuery query;
        query.exec("SELECT * FROM rectangle");

        while (query.next()) {

            QSqlRecord rec = query.record();

            int id = query.value(rec.indexOf("id")).toInt();

            QString pcStr = query.value(rec.indexOf("penColor")).toString();
            QColor penColor = QColor(pcStr);

            int penWidth = query.value(rec.indexOf("penWidth")).toInt();

            int psInt = query.value (rec.indexOf("penStyle")).toInt();
            Qt::PenStyle PenStyle = Qt::PenStyle(psInt);

            int rectLeft = query.value (rec.indexOf("rectLeft")).toInt();
            int rectTop = query.value (rec.indexOf("rectTop")).toInt();
            int rectWidth = query.value (rec.indexOf("rectWidth")).toInt();
            int rectHeight = query.value (rec.indexOf("rectHeight")).toInt();

            qDebug() << id << " - " << penColor << " - " << penWidth << " - " << PenStyle;
            qDebug() << rectLeft << " - " << rectTop << " - " << rectWidth << " - " << rectHeight;
            qDebug() << "----------------------------------------------------";

         }

    }
    else
        qDebug() << db.lastError();

}

void DataBaseController::doQuery()
{
    QString queryStr = QInputDialog::getText(nullptr, "Введите текст запроса:", "Запрос");
    QSqlQuery query;

    bool res = query.exec(queryStr);

    if (!res)
        qDebug() << query.lastError();
    else
        qDebug() << "Запрос выполнен";
}

