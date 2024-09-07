#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QString>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QVariantList>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQueryModel>

class DBManager {
public:
    static DBManager& instance();

    bool exec(const QString& queryStr);

QSqlQueryModel* execQuery(const QString& queryStr);
    QVariant selectSingle(const QString& queryStr);
private:
    DBManager();

    ~DBManager();

//stergere constructor copiere + operator copiere
    DBManager(const DBManager&) = delete;
    DBManager& operator=(const DBManager&) = delete;

    QSqlDatabase _db;
    QString errStr;
};

#endif // DBMANAGER_H
