#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QtSql>
#include <QSqlDatabase>
#include <myrect.h>

class DataBaseController
{
private:
    QSqlDatabase db;
    const QString tableName = "rectangle";

public:
    DataBaseController() { };
    QSqlDatabase getDb() { return db; };
    QString table() { return tableName; };

    void createConnection();
    void closeConnection();
    void createTable();
    void dropTable();
    void insertInto();
    void printTable();
    void doQuery();
};

#endif // DATABASECONTROLLER_H
