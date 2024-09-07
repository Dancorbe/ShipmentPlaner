#include "DBManager.h"
#include <QDebug>


DBManager& DBManager::instance() {
    static DBManager instance;
    return instance;


}


DBManager::DBManager() {
    _db = QSqlDatabase::addDatabase("QODBC");
    _db.setDatabaseName("DRIVER={SQL Server};SERVER=DAN\\SQLEXPRESS;DATABASE=OrdersDB;");

    if (!_db.open()) {
        qDebug() << "Error: Unable to connect to database!";
        qDebug() << _db.lastError().text();
    }
}

DBManager::~DBManager() {
    if (_db.isOpen()) {
        _db.close();
    }
}

bool DBManager::exec(const QString& queryStr) {
    QSqlQuery query(_db);
    if (!query.exec(queryStr)) {
        qDebug() << "Error: Unable to execute query!";
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}




QSqlQueryModel* DBManager::execQuery(const QString& queryStr) {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(queryStr, _db);

    if (model->lastError().isValid()) {
        qDebug() << "Error: Unable to execute query!";
        qDebug() << model->lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}

QVariant DBManager::selectSingle(const QString& queryStr) {
    QSqlQuery query(_db);

    if (!query.exec(queryStr)) {
        qDebug() << "Error: Unable to execute query!";
        qDebug() << query.lastError().text();
        return QVariant();
    }

    if (query.next()) {
        return query.value(0);
    } else {
        qDebug() << "Error: No result found!";
        return QVariant();
    }
}
