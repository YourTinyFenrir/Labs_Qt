#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QtSql>
#include <QSqlDatabase>
#include <myrect.h>

class DataBaseController
{
private:
    QSqlDatabase db;

public:
    DataBaseController() { };

    void createConnection();
    void closeConnection();
    void createTables();

    const QSqlDatabase& getDb() { return db; };
};

#endif // DATABASECONTROLLER_H
