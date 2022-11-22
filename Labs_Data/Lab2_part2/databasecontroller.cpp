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

void DataBaseController::createTables()
{
    if (db.isValid()) {

        QString queryStr = "CREATE TABLE figure ( "
                           "id INTEGER  PRIMARY KEY, "
                           "id_type INTEGER, "
                           "penColor  VARCHAR, "
                           "penStyle  INTEGER, "
                           "penWidth INTEGER, "
                           "rectLeft INTEGER, "
                           "rectTop INTEGER, "
                           "rectWidth INTEGER, "
                           "rectHeight INTEGER) ";

        QSqlQuery query;
        if (query.exec(queryStr))
            qDebug() << "Таблица 'figure' создана";
        else
            qDebug() << query.lastError();

        queryStr = "CREATE TABLE type ( "
                   "id INTEGER  PRIMARY KEY, "
                   "type_name VARCHAR) ";

        if (query.exec(queryStr))
            qDebug() << "Таблица 'type' создана";
        else
            qDebug() << query.lastError();
    }
    else
        qDebug() << db.lastError();
}
